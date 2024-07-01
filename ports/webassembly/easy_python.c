#include <stdint.h>

void value_return(uint64_t ptr, uint64_t len);

void mp_js_init();
int mp_js_do_str(const char* src);
int mp_js_get_int(const char* name);

__attribute__((export_name("hello_easy_python")))
void hello_easy_python() {
    //mp_js_init();

    //mp_js_do_str("result = 42");

    //int32_t result = mp_js_get_int("result");

    value_return(0, sizeof(int32_t));
}
