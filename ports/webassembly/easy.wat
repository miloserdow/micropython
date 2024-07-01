(module
  (import "env" "value_return" (func $value_return (param i64 i64)))
  (func $hello_easy (export "hello_easy")
    ;; Store the value 42 at memory location 0
    i32.const 0
    i32.const 42
    i32.store

    ;; Push the pointer (0) and length (4) of our result onto the stack
    i64.const 0  ;; pointer
    i64.const 4  ;; length (4 bytes for i32)
    
    ;; Call value_return
    call $value_return
  )
  (memory 1)
  (export "memory" (memory 0))
)
