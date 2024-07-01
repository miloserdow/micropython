#include "near_api.h"
#include <emscripten.h>

EM_JS(void, near_input, (uint64_t register_id), {
    env.input(register_id);
});

EM_JS(void, near_read_register, (uint64_t register_id, uint64_t ptr), {
    env.read_register(register_id, ptr);
});

EM_JS(uint64_t, near_register_len, (uint64_t register_id), {
    return env.register_len(register_id);
});

EM_JS(void, near_value_return, (uint64_t value_len, uint64_t value_ptr), {
    env.value_return(value_len, value_ptr);
});

EM_JS(void, near_log_utf8, (uint64_t len, uint64_t ptr), {
    env.log_utf8(len, ptr);
});
