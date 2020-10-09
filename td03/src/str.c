/**
 * @file str.c
 * @author Andrew SASSOYE
 */
#include "str.h"

size_t strlen(const char *str) {
    int count = 0;
    while(str[count] != '\0') {
        ++count;
    }

    return count;
}

int strcmp(const char *lhs, const char *rhs) {
    if (rhs[0] == '\0') {
        return lhs[0];
    }

    if (lhs[0] == '\0') {
        return rhs[0];
    }

    return lhs[0] == rhs[0] ? strcmp(&lhs[1], &rhs[1]) : lhs[0] - rhs[0];
}

char *strcpy( char *dest, const char *src ) {
    size_t length = strlen(src);

    return strncpy(dest, src, length);
}

char *strncpy( char *dest, const char *src, size_t count )  {
    for (size_t i = 0; i < count; ++i) {
        dest[i] = src[i];
    }
    dest[count] = '\0';

    return dest;
}
