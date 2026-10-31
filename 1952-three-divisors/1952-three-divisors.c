
#include <stdbool.h>

bool isThree(int n) {
    int root = 1;

    while (root * root < n) {
        root++;
    }

    if (root * root != n)
        return false;

    if (root < 2)
        return false;

    for (int i = 2; i * i <= root; i++) {
        if (root % i == 0)
            return false;
    }

    return true;
}
