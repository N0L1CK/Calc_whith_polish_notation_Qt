#include "parse.h"

void str_replace(char* buf, int size_buf, const char* str,
                 const char* for_replace, const char* to_replace) {
    const char* ptr;
    int len1 = strlen(for_replace);
    int len2 = strlen(to_replace);

    size_buf -= 1;
    while ((ptr = strstr(str, for_replace)) != NULL) {
        size_buf -= (ptr - str) + len2;
        if (size_buf < 1)
            break;
        strncpy(buf, str, (int)(ptr - str));
        buf += ptr - str;
        strncpy(buf, to_replace, len2);
        buf += len2;
        str = ptr + len1;
    }
    while ((*(buf++) = *(str++)) && (size_buf > 0)) {
        size_buf--;
    }
}

void replace(char* str, const char* for_replace, const char* to_replace) {
    char buf[256];
    str_replace(buf, sizeof(buf) - 1, str, for_replace, to_replace);
    memcpy(str, buf, 256);
}

void replace_all(char* str) {
    replace(str, "mod", "%");
    replace(str, "asin", "A");
    replace(str, "sin", "B");
    replace(str, "acos", "C");
    replace(str, "cos", "D");
    replace(str, "atan", "E");
    replace(str, "tan", "F");
    replace(str, "sqrt", "G");
    replace(str, "ln", "H");
    replace(str, "log", "I");
    replace(str, "\n", "");
}

int is_digit(int arg) {
    int check = (arg >= 48 && arg <= 57) ? 1 : 0;
    return check;
}

void to_postfix(char* str) {
    int j = 0;
    char buf[256] = "";
    char symbols[] = "(+-*/%^~ABCDEFGHI";
    const int priority[] = {0, 1, 1, 2, 2, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5};
    element first = {'\0', 0, NULL};
    element* head = init(first);
    for (int i = 0; i < (int)strlen(str); i++) {
        if (str[i] == 'x') {
            buf[j] = str[i];
            buf[j + 1] = ' ';
            j += 2;
        } else if (is_digit(str[i]) || str[i] == '.') {
            while (is_digit(str[i]) || str[i] == '.')
                buf[j++] = str[i++];
            buf[j++] = ' ';
            i--;
        } else if (str[i] == '(') {
            push_c(str[i], &head);
        } else if (str[i] == ')') {
            while (head->data_c != '(')
                buf[j++] = pop_c(&head);
            pop_c(&head);
        } else if (strchr(symbols, str[i])) {
            if (str[i] == '-' && (i == 0 || (i > 1 && strchr(symbols, str[i - 1]))))
                str[i] = '~';
            while (head->data_c != '\0' && (priority[strchr(symbols, head->data_c) - symbols] >=
                                            priority[strchr(symbols, str[i]) - symbols]))
                buf[j++] = pop_c(&head);
            push_c(str[i], &head);
        }
    }
    while (head->data_c != '\0')
        buf[j++] = pop_c(&head);

    destroy(&head);

    memcpy(str, buf, 256);
}
