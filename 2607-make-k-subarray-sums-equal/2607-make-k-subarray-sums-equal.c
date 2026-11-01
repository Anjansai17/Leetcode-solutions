
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

long long makeSubKSumEqual(int* arr, int arrSize, int k) {
    int g = gcd(arrSize, k);
    long long ans = 0;

    int *temp = malloc(arrSize * sizeof(int));

    for (int i = 0; i < g; i++) {
        int count = 0;

        for (int j = i; j < arrSize; j += g) {
            temp[count++] = arr[j];
        }

        qsort(temp, count, sizeof(int), compare);

        int median = temp[count / 2];

        for (int j = 0; j < count; j++) {
            long long diff = (long long)temp[j] - median;
            ans += llabs(diff);
        }
    }

    free(temp);
    return ans;
}
