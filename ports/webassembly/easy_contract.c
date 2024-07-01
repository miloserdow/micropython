#include <stdint.h>

void value_return(uint64_t ptr, uint64_t len);

__attribute__((export_name("hello_easy_c")))
void hello_easy_c() {
    value_return(0, 4);
}

