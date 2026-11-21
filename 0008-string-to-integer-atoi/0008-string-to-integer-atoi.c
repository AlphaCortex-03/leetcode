#include <limits.h>
#include <stdio.h>

int myAtoi(const char* s) {
    int i = 0;

    while (s[i] == ' ') {
        i++;
    }

    int sign = 1;
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    int num = 0;
    const int limit_div_10 = INT_MAX / 10;

    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        if (num > limit_div_10 || (num == limit_div_10 && digit > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        if (sign == -1 && num == limit_div_10 && digit == 8) {
            return INT_MIN;
        }

        num = num * 10 + digit;
        i++;
    }

    return sign * num;
}


