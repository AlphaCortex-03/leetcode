#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);

    if (n <= 1) {
        return strdup(s);
    }

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
     
        int left = i;
        int right = i;

        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;

            if (len > maxLen) {
                maxLen = len;
                start = left;
            }

            left--;
            right++;
        }

        left = i;
        right = i + 1;

        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;

            if (len > maxLen) {
                maxLen = len;
                start = left;
            }

            left--;
            right++;
        }
    }

    char* result = malloc((maxLen + 1) * sizeof(char));

    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}
