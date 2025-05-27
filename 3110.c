#include <math.h>

int scoreOfString(char* s) {
    char *c = s;
    int score = 0;
    while (*(++c) != '\0') {
        score += abs(*c - *(c - 1));
    }
    return score;
}
