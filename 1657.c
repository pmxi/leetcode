// observation
// strings are only close if they have equal length
// it is not possible to introduce a new character
// so they must contain the same characters
// "aba" "abb" {a: 2, b: 1} and {a: 1, b: 2}
//
// problem: two arrays of nums [1, 4, 2] and [2, 1, 4]. Do they contain the same numbers?
// Conjecture: string1 and string2 are CLOSE if:
// 1) Lengths are equal (redundant with property 3)
// 2) Characters used are the same
// 3) Frequencies are the same, but not necessarily to the same characters.


#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp_uint(const void *a, const void *b);

#define ALPHABET_SIZE (26)

bool closeStrings(char *word1, char *word2) {

    unsigned int freq1[ALPHABET_SIZE] = {0};
    for (; *word1; word1++) {
        freq1[*word1 - 'a']++;
    }

    unsigned int freq2[ALPHABET_SIZE] = {0};
    for (; *word2; word2++) {
        freq2[*word2 - 'a']++;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if ((freq1[i] == 0) != (freq2[i] == 0)) {
            return false;
        }
    }

    qsort(freq1, ALPHABET_SIZE, sizeof(unsigned int), cmp_uint);
    qsort(freq2, ALPHABET_SIZE, sizeof(unsigned int), cmp_uint);


    return memcmp(freq1, freq2, sizeof(freq1)) == 0;
}

int cmp_uint(const void *a, const void *b) {
    unsigned int ua = *(const unsigned int*)a;
    unsigned int ub = *(const unsigned int*)b;
    // return negative if ua<ub, zero if equal, positive if ua>ub
    return (ua > ub) - (ua < ub);
}
