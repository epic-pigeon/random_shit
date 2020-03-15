//
// Created by nikit on 3/15/2020.
//

#include "functions.h"
#include "string.h"
#include "stdlib.h"

i32 funlen(void* fun) {
    i8_ptr copy = fun;
    while (*copy != (i8)0xc3) {
        copy++;
    }
    return copy - (i8_ptr)fun;
}

void* fundup(void* fun) {
    i32 length = funlen(fun);
    void* result = malloc(length + 1);
    memcpy(result, fun, length + 1);
    return result;
}
