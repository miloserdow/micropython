#!/bin/bash

#!/bin/bash

emcc -Oz \
    micropython_exports.c \
    ../../py/mpstate.c \
    ../../py/nlr.c \
    ../../py/obj.c \
    ../../py/objtype.c \
    ../../py/runtime.c \
    ../../py/gc.c \
    ../../py/malloc.c \
    ../../py/qstr.c \
    ../../py/vstr.c \
    ../../py/mpprint.c \
    ../../py/parse.c \
    ../../py/lexer.c \
    ../../py/scope.c \
    ../../py/compile.c \
    ../../py/emitcommon.c \
    ../../py/emitbc.c \
    ../../py/asmbase.c \
    ../../py/asmx64.c \
    ../../py/emitnx64.c \
    ../../py/asmx86.c \
    ../../py/emitnx86.c \
    ../../py/asmthumb.c \
    ../../py/emitnthumb.c \
    ../../py/emitinlinethumb.c \
    ../../py/asmarm.c \
    ../../py/emitnarm.c \
    ../../py/formatfloat.c \
    ../../py/parsenumbase.c \
    ../../py/parsenum.c \
    ../../py/emitglue.c \
    ../../py/persistentcode.c \
    ../../py/scheduler.c \
    ../../py/nativeglue.c \
    ../../py/pairheap.c \
    ../../py/ringbuf.c \
    ../../py/stackctrl.c \
    ../../py/argcheck.c \
    ../../py/warning.c \
    ../../py/profile.c \
    ../../py/map.c \
    ../../py/objarray.c \
    ../../py/objbool.c \
    ../../py/objboundmeth.c \
    ../../py/objcell.c \
    ../../py/objclosure.c \
    ../../py/objcomplex.c \
    ../../py/objdeque.c \
    ../../py/objdict.c \
    ../../py/objenumerate.c \
    ../../py/objexcept.c \
    ../../py/objfilter.c \
    ../../py/objfloat.c \
    ../../py/objfun.c \
    ../../py/objgenerator.c \
    ../../py/objgetitemiter.c \
    ../../py/objint.c \
    ../../py/objlist.c \
    ../../py/objmap.c \
    ../../py/objmodule.c \
    ../../py/objobject.c \
    ../../py/objpolyiter.c \
    ../../py/objproperty.c \
    ../../py/objnone.c \
    ../../py/objnamedtuple.c \
    ../../py/objrange.c \
    ../../py/objreversed.c \
    ../../py/objset.c \
    ../../py/objsingleton.c \
    ../../py/objslice.c \
    ../../py/objstr.c \
    ../../py/objstrunicode.c \
    ../../py/objstringio.c \
    ../../py/objtuple.c \
    ../../py/objtype.c \
    ../../py/objzip.c \
    ../../py/opmethods.c \
    ../../py/sequence.c \
    ../../py/stream.c \
    ../../py/binary.c \
    ../../py/builtinimport.c \
    ../../py/builtinevex.c \
    ../../py/builtinhelp.c \
    ../../py/modarray.c \
    ../../py/modbuiltins.c \
    ../../py/modcollections.c \
    ../../py/modgc.c \
    ../../py/modio.c \
    ../../py/modmath.c \
    ../../py/modcmath.c \
    ../../py/modmicropython.c \
    ../../py/modstruct.c \
    ../../py/modsys.c \
    ../../py/modthread.c \
    ../../py/vm.c \
    ../../py/bc.c \
    ../../py/showbc.c \
    ../../py/repl.c \
    ../../py/smallint.c \
    ../../py/frozenmod.c \
    -o micropython_core.wasm \
    -I. -I../.. -I../../py -Ivariants/standard/ -Ibuild-standard/ \
    -s SIDE_MODULE=2 \
    -s EXPORTED_FUNCTIONS='["_mp_js_init","_mp_js_do_str","_mp_js_get_int"]' \
    -s EXPORTED_RUNTIME_METHODS=[] \
    -s ALLOW_MEMORY_GROWTH=1 \
    --no-entry


#emcc -Oz \
#    micropython_exports.c \
#    ../../py/*.c \
#    -o micropython_core.wasm \
#    -I. -I../.. -I../../py -Ivariants/standard/ -Ibuild-standard/ \
#    -s SIDE_MODULE=2 \
#    -s EXPORTED_FUNCTIONS='["_mp_js_init","_mp_js_do_str","_mp_js_get_int"]' \
#    -s EXPORTED_RUNTIME_METHODS=[] \
#    -s ALLOW_MEMORY_GROWTH=0 \
#    --no-entry
