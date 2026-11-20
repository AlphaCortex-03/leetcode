#include <stdlib.h>
#include <string.h>

void dfs(int n, int o, int c, char *s, int i, char **ans, int *k) {
    if (i == 2 * n) { s[i] = 0; ans[(*k)++] = strdup(s); return; }
    if (o < n) { s[i] = '('; dfs(n, o + 1, c, s, i + 1, ans, k); }
    if (c < o) { s[i] = ')'; dfs(n, o, c + 1, s, i + 1, ans, k); }
}

char** generateParenthesis(int n, int* returnSize) {
    char **ans = malloc(1430 * sizeof(char*)), *s = malloc(2 * n + 1);
    int k = 0;
    dfs(n, 0, 0, s, 0, ans, &k);
    free(s);
    return *returnSize = k, ans;
}