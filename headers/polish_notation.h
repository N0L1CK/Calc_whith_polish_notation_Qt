#ifndef SRC_HEADERS_POLISH_NOTATION_H_
#define SRC_HEADERS_POLISH_NOTATION_H_

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "parse.h"

double operations(char ch, double first, double second);
double calc(char *str, double x);

#endif  // SRC_HEADERS_POLISH_NOTATION_H_
