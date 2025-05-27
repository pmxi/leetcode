// haha
// credit: https://stackoverflow.com/a/47846874/18600897
static inline bool isvowel(char v) {
    return (0x208222>>(v&0x1f))&1;
}

int maxVowels(char* s, int k) {
    int vowels = 0;
    for (int i = 0; i < k; i++) {
        if (isvowel(s[i])) vowels++;
    }
    int max_vowels = vowels;
    for (int j = k; s[j] != '\0'; j++) {
        if (isvowel(s[j - k])) vowels--;
        if (isvowel(s[j])) vowels++;
        if (vowels > max_vowels) max_vowels = vowels;
    }
    return max_vowels;
}

