// https://stackoverflow.com/questions/47846406/c-fastest-way-to-check-if-char-is-vowel-or-consonant
// bool isvowel(char v) {
//     return (v > 0x60) && (0x208222>>(v&0x1f))&1;
// }

bool isvowel(char c) {
    switch (c) {
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
            return false;
    }
}




char* reverseVowels(char* s) {
    char temp;
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        if (!isvowel(s[i])) {
            i++;
            continue;
        }
        if (!isvowel(s[j])) {
            j--;
            continue;
        }
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return s;
}
