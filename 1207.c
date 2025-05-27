#include <stdbool.h>


bool uniqueOccurrences(int* arr, int arrSize) {
    unsigned short occurences[2001] = {0};
    for (int i = 0; i < arrSize; i++) {
        occurences[arr[i] + 1000]++;
    }
    // each occurences is in [0, 1000]
    // because arr.length is at most 1000.
    unsigned short occurencesOccurences[1001] = {0};

    for (int j = 0; j < 2001; j++) {
        occurencesOccurences[occurences[j]]++;
    }

    for (int k = 1; k < 1000; k++) {
        if (occurencesOccurences[k] > 1) {
            return false;
        }
    }
    return true;
}
