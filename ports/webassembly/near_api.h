#ifndef MICROPY_INCLUDED_WASM_NEAR_API_H
#define MICROPY_INCLUDED_WASM_NEAR_API_H

#include "py/obj.h"

void near_input(uint64_t register_id);
void near_read_register(uint64_t register_id, uint64_t ptr);
uint64_t near_register_len(uint64_t register_id);
void near_value_return(uint64_t value_len, uint64_t value_ptr);
void near_log_utf8(uint64_t len, uint64_t ptr);

#endif // MICROPY_INCLUDED_WASM_NEAR_API_H
