
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int matrixSum(int** nums, int numsSize, int* numsColSize) {
    int ans = 0;
    int cols = numsColSize[0];

    for (int i = 0; i < numsSize; i++) {
        qsort(nums[i], cols, sizeof(int), compare);
    }

    for (int j = 0; j < cols; j++) {
        int max = 0;

        for (int i = 0; i < numsSize; i++) {
            if (nums[i][j] > max) {
                max = nums[i][j];
            }
        }

        ans += max;
    }

    return ans;
}
