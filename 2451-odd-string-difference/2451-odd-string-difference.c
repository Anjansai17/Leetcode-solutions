
#include <string.h>

char* oddString(char** words, int wordsSize) {
    int len = strlen(words[0]);

    for (int i = 0; i < wordsSize; i++) {
        int count = 0;

        for (int j = 0; j < wordsSize; j++) {
            if (i == j)
                continue;

            int same = 1;

            for (int k = 0; k < len - 1; k++) {
                int d1 = words[i][k + 1] - words[i][k];
                int d2 = words[j][k + 1] - words[j][k];

                if (d1 != d2) {
                    same = 0;
                    break;
                }
            }

            if (same)
                count++;
        }

        if (count == 0)
            return words[i];
    }

    return "";
}
