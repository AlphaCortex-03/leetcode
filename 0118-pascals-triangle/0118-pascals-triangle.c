int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    int* colSizes = (int*)malloc(numRows * sizeof(int));
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = colSizes;

    for (int i = 0; i < numRows; i++) {
        int cols = i + 1;
        colSizes[i] = cols;

        int* row = (int*)malloc(cols * sizeof(int));
        triangle[i] = row;
        row[0] = 1;
        row[i] = 1;

        if (i > 1) {
            int* prev = triangle[i - 1];
            int mid = i >> 1; 
            for (int j = 1; j <= mid; j++) {
                int val = prev[j - 1] + prev[j];
                row[j] = val;
                row[i - j] = val;
            }
        }
    }

    return triangle;
}