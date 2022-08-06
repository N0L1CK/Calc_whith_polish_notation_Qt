#ifndef SRC_HEADERS_PARSE_H_
#define SRC_HEADERS_PARSE_H_

#include <stdio.h>
#include <string.h>

#include "stack.h"

void str_replace(char* buf, int size_buf, const char* str,
                 const char* for_replace, const char* to_replace);
void replace(char* str, const char* for_replace, const char* to_replace);
void replace_all(char* str);
int is_digit(int arg);
void to_postfix(char* str);

#endif  // SRC_HEADERS_PARSE_H_
