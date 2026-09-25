#include <string.h>

int romanToInt(char* s) {
    char *symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L",
                      "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    int result = 0;

    while (*s) {
        for (int j = 0; j < 13; j++) {
            int len = strlen(symbol[j]);

            if (strncmp(s, symbol[j], len) == 0) {
                result += values[j];
                s += len; 
                break; 
            }
        }
    }

    return result; 
}