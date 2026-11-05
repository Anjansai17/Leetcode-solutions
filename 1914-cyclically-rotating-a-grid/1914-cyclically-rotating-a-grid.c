
#include <stdlib.h>

int** rotateGrid(int** grid, int gridSize, int* gridColSize,
                 int k, int* returnSize, int** returnColumnSizes) {

    int m = gridSize;
    int n = gridColSize[0];

    *returnSize = m;
    *returnColumnSizes = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        (*returnColumnSizes)[i] = n;

    int layers = (m < n ? m : n) / 2;

    for (int layer = 0; layer < layers; layer++) {
        int top = layer, left = layer;
        int bottom = m - 1 - layer;
        int right = n - 1 - layer;

        int len = 2 * (bottom - top + right - left);
        int shift = k % len;

        int *temp = malloc(len * sizeof(int));
        int idx = 0;

        for (int j = left; j <= right; j++)
            temp[idx++] = grid[top][j];

        for (int i = top + 1; i <= bottom; i++)
            temp[idx++] = grid[i][right];

        for (int j = right - 1; j >= left; j--)
            temp[idx++] = grid[bottom][j];

        for (int i = bottom - 1; i > top; i--)
            temp[idx++] = grid[i][left];

        idx = 0;

        for (int j = left; j <= right; j++)
            grid[top][j] = temp[(idx++ + shift) % len];

        for (int i = top + 1; i <= bottom; i++)
            grid[i][right] = temp[(idx++ + shift) % len];

        for (int j = right - 1; j >= left; j--)
            grid[bottom][j] = temp[(idx++ + shift) % len];

        for (int i = bottom - 1; i > top; i--)
            grid[i][left] = temp[(idx++ + shift) % len];

        free(temp);
    }

    return grid;
}
