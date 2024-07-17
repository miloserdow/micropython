#include <stdint.h>
#include "py/mpconfig.h"
#include "py/mpstate.h"
#include "py/builtin.h"
#include "py/obj.h"
#include "py/compile.h"
#include "py/runtime.h"
#include "py/gc.h"

extern void value_return(uint64_t value_len, uint64_t value_ptr);

//#define HEAP_SIZE 32768

//static char heap[HEAP_SIZE];

void init_micropython(void) {
  //  gc_init(heap, heap + sizeof(heap));
   mp_init();
}


void mp_sum() {
   init_micropython();
    
    //mp_obj_t args[2] = {mp_obj_new_int(40), mp_obj_new_int(2)};
    //mp_obj_t fun = mp_load_name(qstr_from_str("sum"));
    //mp_obj_t result = mp_call_function_n_kw(fun, 2, 0, args);

    //mp_lexer_t *lex = mp_lexer_new_from_str_len(MP_QSTR__lt_stdin_gt_, "sum(a, b)", 9, false);
    //mp_parse_tree_t pt = mp_parse(lex, MP_PARSE_EVAL_INPUT);
    //mp_obj_t module_fun = mp_compile(&pt, lex->source_name, false);

    //mp_obj_t result = mp_call_function_n_kw(module_fun, 2, 0, args);

    //value_return(mp_obj_get_int(result), sizeof(uint32_t));
    value_return(4, 0);
}

void c_sum(uint32_t a, uint32_t b) {
    value_return(sizeof(uint32_t), (a + b));
}

void sanity_check() {
    value_return(0, 4);
}
