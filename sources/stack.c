#include "stack.h"


element* init(element first) {
    element* root = (element*)malloc(sizeof(element));
    root->data_c = first.data_c;
    root->data_d = first.data_d;
    root->next = first.next;
    return root;
}

void push_c(char data, element** stack) {
    element* Element = (element*)malloc(sizeof(element));
    Element->data_c = data;
    Element->next = *stack;
    (*stack) = Element;
}

char pop_c(element** stack) {
    char res;
    if (*stack != NULL) {
        element* tempPtr = *stack;
        res = tempPtr->data_c;
        *stack = (*stack)->next;
        free(tempPtr);
    } else {
        res = '\0';
    }
    return res;
}

void push_d(double data, element** stack) {
    element* Element_d = (element*)malloc(sizeof(element));
    Element_d->data_d = data;
    Element_d->next = *stack;
    (*stack) = Element_d;
}

double pop_d(element** stack) {
    double res = 0.0;
    if (*stack != NULL) {
        element* tempPtr = *stack;
        res = tempPtr->data_d;
        *stack = (*stack)->next;
        free(tempPtr);
    } else {
        res = 0.0;
    }
    return res;
}

void destroy(element** stack) {
    while (*stack != NULL) {
        element* tempPtr = *stack;
        *stack = (*stack)->next;
        free(tempPtr);
    }
}
