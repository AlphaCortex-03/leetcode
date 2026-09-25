#include <string.h>
#include <stdlib.h>

char* intToRoman(int num) {
    char *symbol[] = {
        "M", "CM", "D", "CD", "C", "XC",
        "L", "XL", "X", "IX", "V", "IV", "I"
    };

    int values[] = {
        1000, 900, 500, 400, 100, 90,
        50, 40, 10, 9, 5, 4, 1
    };

    char *result = malloc(16 * sizeof(char));

    if (!result)
        return NULL;

    result[0] = '\0';

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(result, symbol[i]);
            num -= values[i];
        }
    }

    return result;
}