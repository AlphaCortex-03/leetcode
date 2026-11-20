#include <stdlib.h>
#include <string.h>

static void backtrack(
    int n,
    int open,
    int close,
    char* current,
    int index,
    char*** result,
    int* count,
    int* capacity
) {
    if (index == 2 * n) {
        current[index] = '\0';

        if (*count == *capacity) {
            *capacity *= 2;
            char** resized = realloc(*result, sizeof(char*) * (*capacity));
            if (!resized) {
                return;
            }
            *result = resized;
        }

        char* copy = malloc((size_t)(2 * n + 1) * sizeof(char));
        if (!copy) {
            return;
        }
        strcpy(copy, current);
        (*result)[*count] = copy;
        (*count)++;
        return;
    }

    if (open < n) {
        current[index] = '(';
        backtrack(n, open + 1, close, current, index + 1, result, count, capacity);
    }

    if (close < open) {
        current[index] = ')';
        backtrack(n, open, close + 1, current, index + 1, result, count, capacity);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    if (n <= 0) {
        return NULL;
    }

    int capacity = 1024;
    int count = 0;
    char** result = malloc(sizeof(char*) * capacity);
    char* current = malloc((size_t)(2 * n + 1) * sizeof(char));

    if (!result || !current) {
        free(result);
        free(current);
        return NULL;
    }

    backtrack(n, 0, 0, current, 0, &result, &count, &capacity);

    free(current);
    *returnSize = count;
    return result;
}