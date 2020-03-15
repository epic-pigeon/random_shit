#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "printstream.h"
#include "functions.h"
#include "types.h"

void fake_print(printstream* a, char* b) {
    u8* this = 0xdeadbeef;
    (*this)++;
}

int main() {
    /*FILE* file = fopen("C:\\Users\\nikit\\CLionProjects\\ctest\\kar.txt", "w");
    printstream_ptr ps = new_printstream(file);
    printstream_printf(ps, "kar %d%s", 1, ps->newLine);
    ps->println(ps, "kar");
    ps->print(ps, "ne kar\n");
    ps->print = fake_print;
    ps->print(ps, "ne kar");*/
    printf("%d\n", funlen(fake_print));
    void(*cpy)(printstream*, char*);
    cpy = fundup(fake_print);
    printf("%x\n", ((u8_ptr)cpy)[funlen(fake_print)]);
    char a = 'A';
    fake_print(0, &a);
    printf("0x%x\n", a);
    cpy(0, &a);
    printf("0x%x\n", a);
    return 0;
}

