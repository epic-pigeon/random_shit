//
// Created by nikit on 3/14/2020.
//

#include "printstream.h"

typedef struct printstream_private {
    printstream _printstream;
    FILE* file;
} printstream_private;

printstream* new_printstream(FILE* file) {
    printstream_private* result = malloc(sizeof(printstream_private));
    result->file = file;
    result->_printstream.newLine = "\n";
    result->_printstream.printf = printstream_printf;
    result->_printstream.print = printstream_print;
    result->_printstream.println = printstream_println;
    return result;
};
void printstream_print(printstream* _this, char* str) {
    printstream_private* this = _this;
    fprintf(this->file, "%s", str);
}
void printstream_println(printstream* _this, char* str) {
    printstream_private* this = _this;
    fprintf(this->file, "%s%s", str, this->_printstream.newLine);
}
void printstream_printf(printstream* _this, char* format, ...) {
    printstream_private* this = _this;
    va_list args;
    va_start(args, format);
    vfprintf(this->file, format, args);
    va_end(args);
}
