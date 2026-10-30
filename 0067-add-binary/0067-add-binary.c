#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    
    // Allocate memory for the result (+2 for potential carry extension and null terminator)
    char* res = (char*)malloc(maxLen + 2);
    int i = lenA - 1;
    int j = lenB - 1;
    int k = maxLen + 1;
    res[k--] = '\0';
    
    int carry = 0;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        res[k] = (sum % 2) + '0';
        carry = sum / 2;
        k--;
    }
    
    // Shift the result to the start of the allocated buffer
    int start = k + 1;
    int length = (maxLen + 1) - start;
    memmove(res, res + start, length + 1);
    
    return res;
}