#ifndef SRC_HEADERS_STACK_H_
#define SRC_HEADERS_STACK_H_

#include <stdlib.h>

typedef struct element {
    char data_c;
    double data_d;
    struct element* next;
} element;

element* init(element first);
void push_c(char data, element** stack);
void push_d(double data, element** stack);
char pop_c(element** stack);
double pop_d(element** stack);
void destroy(element** stack);

#endif  // SRC_HEADERS_STACK_H_
