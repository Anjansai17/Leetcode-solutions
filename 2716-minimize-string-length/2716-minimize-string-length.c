
int minimizedStringLength(char* s) {
    int seen[26] = {0};
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (seen[index] == 0) {
            seen[index] = 1;
            count++;
        }
    }

    return count;
}
