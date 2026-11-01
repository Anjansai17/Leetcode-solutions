
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int* closestPrimes(int left, int right, int* returnSize) {
    int *ans = (int*)malloc(2 * sizeof(int));
    int prev = -1;
    int minDiff = 1000000;

    ans[0] = -1;
    ans[1] = -1;

    *returnSize = 2;

    for (int i = left; i <= right; i++) {
        if (isPrime(i)) {
            if (prev != -1 && i - prev < minDiff) {
                minDiff = i - prev;
                ans[0] = prev;
                ans[1] = i;
            }

            prev = i;
        }
    }

    return ans;
}
