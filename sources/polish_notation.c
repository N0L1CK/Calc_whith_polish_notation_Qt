#include "polish_notation.h"

double operations(char ch, double first, double second) {
    double res = 0.0;
    switch (ch) {
        case '-': res = first - second; break;
        case '+': res = first + second; break;
        case '*': res = first * second; break;
        case '/': res = first / second; break;
        case '%': res = fmod(first, second); break;
        case '^': res = pow(first, second); break;
        case 'A': res = asin(first); break;
        case 'B': res = sin(first); break;
        case 'C': res = acos(first); break;
        case 'D': res = cos(first); break;
        case 'E': res = atan(first); break;
        case 'F': res = tan(first); break;
        case 'G': res = sqrt(first); break;
        case 'H': res = log(first); break;
        case 'I': res = log10(first); break;
        default: break;
    }
    return res;
}

double calc(char* str, double x) {
    element first = {'\0', 0, NULL};
    element* head = init(first);
    char symbols[] = "(+-*/%^~ABCDEFGHI";

    for (int i = 0; i < (int)strlen(str); i++) {
        if (str[i] == 'x') {
            push_d(x, &head);
        } else if (is_digit(str[i]) || str[i] == '.') {
            char buf[256] = "";
            int j = 0;
            while (is_digit(str[i]) || str[i] == '.') {
                buf[j] = str[i];
                j++, i++;
            }
            push_d(atof(buf), &head);
        } else if (strchr(symbols, str[i])) {
            if (strchr("ABCDEFGHI", str[i])) {
                push_d(operations(str[i], (double)pop_d(&head), 0.0), &head);
                continue;
            }
            if (str[i] == '~') {
                double last = (head->next != NULL) ? (double)pop_d(&head) : 0.0;
                push_d(operations('-', 0.0, last), &head);
                continue;
            }
            double second = (head->next != NULL) ? (double)pop_d(&head) : 0.0;
            double firstd = (head->next != NULL) ? (double)pop_d(&head) : 0.0;
            push_d(operations(str[i], (double)firstd, (double)second), &head);
        }
    }
    double res = head->data_d;
    destroy(&head);
    return res;
}
