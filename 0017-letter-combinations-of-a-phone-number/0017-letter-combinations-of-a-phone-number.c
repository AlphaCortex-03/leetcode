#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* map[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int total = 1;
    for (int i = 0; i < len; i++) {
        total *= strlen(map[digits[i] - '0']);
    }
    
    char** result = (char**)malloc(total * sizeof(char*));
    for (int i = 0; i < total; i++) {
        result[i] = (char*)malloc((len + 1) * sizeof(char));
        result[i][len] = '\0';
    }
    
    for (int i = 0; i < total; i++) {
        int current_combination_index = i;
        
        for (int j = 0; j < len; j++) {
            const char* letters = map[digits[j] - '0'];
            int num_letters = strlen(letters);
            
            result[i][j] = letters[current_combination_index % num_letters];
            current_combination_index /= num_letters;
        }
    }

    *returnSize = total;
    return result;
}