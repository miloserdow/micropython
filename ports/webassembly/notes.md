# Notes

## What I am trying to achieve
A contract with exported function which calls uPy for some calculation and returns result of this calculation.

## What is achieved
Wrapper and uPy are build and linked together in a single .wasm. 

If uPy is used in runtime, the contract call fails when being prepared for execution by NEAR VM. If uPy is not used by `hello_easy_python`, the exceution of this function succeeds on testnet. 

## What works
(meaning)
- .wasm can be deployed on chain
near contract deploy pywasm-test-account.testnet use-file easy_python.wasm without-init-call network-config testnet sign-with-seed-phrase '***REDACTED***' --seed-phrase-hd-path 'm/44'\''/397'\''/0'\''' send

- Function can be called on NEAR VM successfully
near contract call-function as-transaction pywasm-test-account.testnet hello_easy_python json-args {} prepaid-gas '30.0 Tgas' attached-deposit '0 NEAR' sign-as pywasm-test-account.testnet network-config testnet sign-with-seed-phrase '***REDACTED***' --seed-phrase-hd-path 'm/44'\''/397'\''/0'\''' send

### .wat -> .wasm
wat2wasm easy.wat

### Building and running simple C code -> .wasm
emcc -Oz easy_contract.c -o easy_contract.wasm \
    -s STANDALONE_WASM \    
    -s EXPORTED_FUNCTIONS='["_hello_easy_c"]' \
    -s IMPORTED_MEMORY \
    -s ALLOW_MEMORY_GROWTH=0 \
    -s ERROR_ON_UNDEFINED_SYMBOLS=0

### Building C -> .wasm, with MPy linked but not used
emcc -c micropython_lib.c  -fPIC -I. -I../.. -I../../py -Ivariants/standard/ -Ibuild-standard/ -DMICROPY_PERSISTENT_CODE_LOAD=0 -DMICROPY_VFS_POSIX=0 -o micropython_lib.o

emcc -Oz easy_python.c micropython_lib.o -o easy_python.wasm -s STANDALONE_WASM -s EXPORTED_FUNCTIONS='["_hello_easy_python"]' -s IMPORTED_MEMORY -s ALLOW_MEMORY_GROWTH=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0  --no-entry

This is one iteration better, we link **some** Micropython code into the resulting .wasm but if actually used causes VM to crash on compile time (see below).

## What does not work

### C -> .wasm + mp_init()
Problems with mp_init() - in runtime - Near VM compilation fails

Might be a linking issue, or memory handling issue, for example this code would cause the same error:


Error:
   0: Error: An error occurred during a `FunctionCall` Action, parameter is debug message.
      CompilationError(PrepareError(Memory))

Location:
   src/common.rs:955


### Linking Micropython -> .wasm, then using it as a library
./compile_micropython.sh (fails due to symbols being included twice)

or building .wasm using new makefile rule "make relocatable" - the resulting file is not self-sufficient and relies on missing mp_init

Import[484]:
  21  - memory[0] pages: initial=1 <- env.memory
  20  - table[0] type=funcref initial=433 <- env.__indirect_function_table
  19  - global[0] i32 mutable=1 <- env.__stack_pointer
  18  - global[1] i32 mutable=0 <- env.__memory_base
  17  - global[2] i32 mutable=0 <- env.__table_base
  16  - func[0] sig=3 <emscripten_longjmp> <- env.emscripten_longjmp
  15  - func[1] sig=6 <memset> <- env.memset
  14  - func[2] sig=6 <memcpy> <- env.memcpy
  13  - func[3] sig=6 <strncmp> <- env.strncmp
  12  - func[4] sig=6 <memcmp> <- env.memcmp
  11  - func[5] sig=2 <strlen> <- env.strlen
  10  - func[6] sig=6 <memmove> <- env.memmove
   9  - func[7] sig=5 <strcmp> <- env.strcmp
   8  - func[8] sig=3 <mp_reader_new_file> <- env.mp_reader_new_file
   7  - func[9] sig=10 <pow> <- env.pow
   6  - func[10] sig=11 <nan> <- env.nan
   5  - func[11] sig=5 <invoke_ii> <- env.invoke_ii
   4  - func[12] sig=5 <__wasm_setjmp_test> <- env.__wasm_setjmp_test
   3  - func[13] sig=0 <setTempRet0> <- env.setTempRet0
   2  - func[14] sig=8 <getTempRet0> <- env.getTempRet0
   1  - func[15] sig=4 <invoke_viii> <- env.invoke_viii
71    - func[16] sig=1 <__wasm_setjmp> <- env.__wasm_setjmp
[...]

Of course, those functions are not available and their implementation should be included in the .wasm

