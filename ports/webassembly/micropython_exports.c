#include <string.h>
#include "py/compile.h"
#include "py/runtime.h"
#include "py/gc.h"
#include "py/mperrno.h"

#define MICROPY_HEAP_SIZE (256 * 1024)
static char heap[MICROPY_HEAP_SIZE];

__attribute__((visibility("default")))
void mp_js_init(void) {
    mp_stack_set_limit(10000);
    gc_init(heap, heap + sizeof(heap));
    mp_init();
}

__attribute__((visibility("default")))
void mp_js_do_str(const char* src) {
    nlr_buf_t nlr;
    if (nlr_push(&nlr) == 0) {
        mp_lexer_t *lex = mp_lexer_new_from_str_len(MP_QSTR__lt_stdin_gt_, src, strlen(src), 0);
        mp_parse_tree_t parse_tree = mp_parse(lex, MP_PARSE_FILE_INPUT);
        mp_obj_t module_fun = mp_compile(&parse_tree, lex->source_name, false);
        mp_call_function_0(module_fun);
        nlr_pop();
    } else {
        mp_obj_print_exception(&mp_plat_print, (mp_obj_t)nlr.ret_val);
    }
}

__attribute__((visibility("default")))
int mp_js_get_int(const char* name) {
    mp_obj_t obj = mp_load_name(qstr_from_str(name));
    return mp_obj_get_int(obj);
}
