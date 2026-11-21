#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int myAtoi(char* s) {
    int i = 0;
    long result = 0;
    int sign = 1;

    // 1. Skip leading whitespace
    while (s[i] == ' ') {
        i++;
    }

    // 2. Check optional '+' or '-' sign
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // 3. Convert consecutive digits and handle 32-bit int overflow
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');

        if (sign == 1 && result > INT_MAX) {
            return INT_MAX;
        }
        if (sign == -1 && -result < INT_MIN) {
            return INT_MIN;
        }
        i++;
    }

    return (int)(sign * result);
}
