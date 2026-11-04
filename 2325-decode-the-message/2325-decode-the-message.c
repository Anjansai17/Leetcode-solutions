
#include <string.h>

char* decodeMessage(char* key, char* message) {
    char map[26] = {0};
    char ch = 'a';

    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i] != ' ' && map[key[i] - 'a'] == 0) {
            map[key[i] - 'a'] = ch;
            ch++;
        }
    }

    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] != ' ') {
            message[i] = map[message[i] - 'a'];
        }
    }

    return message;
}
