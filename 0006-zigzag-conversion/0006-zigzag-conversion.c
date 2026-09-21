#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows <= 1 || numRows >= len) {
        char* result = (char*)malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int idx = 0;
    int cycle = 2 * numRows - 2;

    for (int r = 0; r < numRows; r++) {
        for (int j = r; j < len; j += cycle) {
            result[idx++] = s[j]; 

            
            int diag_idx = j + cycle - 2 * r;
            if (r > 0 && r < numRows - 1 && diag_idx < len) {
                result[idx++] = s[diag_idx];
            }
        }
    }

    result[idx] = '\0';
    return result;
}