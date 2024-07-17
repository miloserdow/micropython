#include "py/obj.h"
#include "py/mpconfig.h"

mp_obj_t mp_sys_stdin_obj = MP_OBJ_NULL;
mp_obj_t mp_sys_stdout_obj = MP_OBJ_NULL;
mp_obj_t mp_sys_stderr_obj = MP_OBJ_NULL;


#include <stdint.h>

#include <stdint.h>

int32_t invoke_ii(int32_t a, int32_t b) {
    return 0;
}

void invoke_viii(int32_t a, int32_t b, int32_t c, int32_t d) {
}

int32_t invoke_iiii(int32_t a, int32_t b, int32_t c, int32_t d) {
    return 0;
}

void invoke_v(int32_t a) {
}

int32_t invoke_iii(int32_t a, int32_t b, int32_t c) {
    return 0;
}

void invoke_vi(int32_t a, int32_t b) {
}

void invoke_vii(int32_t a, int32_t b, int32_t c) {
}

int32_t invoke_i(int32_t a) {
    return 0;
}

void mp_js_hook(void) {
}

int32_t invoke_iiiii(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e) {
    return 0;
}

void invoke_viiii(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e) {
}

void emscripten_scan_registers(int32_t a) {
}

uint32_t mp_js_ticks_ms(void) {
    return 0;
}

int fd_write(void) {
    return 0;
}

void _emscripten_throw_longjmp(void) {
}

uint32_t mp_hal_stdout_tx_strn(const char *str, size_t len) {
    return 0;
}

int __wasi_fd_close(int a) {
    return 0;
}

int __wasi_fd_write(int a, int b, int c, int d) {
    return 0;
}
