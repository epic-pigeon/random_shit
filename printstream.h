//
// Created by nikit on 3/14/2020.
//

#ifndef CTEST_PRINTSTREAM_H
#define CTEST_PRINTSTREAM_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct printstream {
    char* newLine;
    void(*print)(struct printstream*, char*);
    void(*println)(struct printstream*, char*);
    void(*printf)(struct printstream*, char*, ...);
} printstream, *printstream_ptr;

printstream* new_printstream(FILE*);
void printstream_print(printstream*, char*);
void printstream_println(printstream*, char*);
void printstream_printf(printstream*, char*, ...);

#endif //CTEST_PRINTSTREAM_H
