/*
 * Process the string s such that:
 *  1) the first character is not a space
 *  2) the last character is not a space
 *  3) No two spaces are next to each other
 * Finally, return the length of the "skipped string"
 */

int skip_spaces(char *s) {
    int i = 0;
    int j = 0;
    // invariant: j <= i

    // skip leading spaces
    while ((s[i] != '\0') && (s[i] == ' ')) i++;

    while (s[i] != '\0') {
        if (s[i] !=  ' ') {
            s[j++] = s[i++];
        }
        else {
            s[j++] = ' ';
            while ((s[i] != '\0') && s[i] == ' ') {
                i++;
            }
        }
    }

    while (j > 0 && s[j - 1] == ' ') j--;

    s[j] = '\0';

    return j;
} /* skip_spaces() */

/*
 * Modify s such that the substring [l, r] appears in reverse order.
 */

void reverse_range(char *s, int l, int r) {
    // temporary variable
    char t = '\0';
    while (l < r) {
        // swap s[l] and s[r]
        t = s[l];
        s[l] = s[r];
        s[r] = t;
        l++;
        r--;
    }
} /* reverse_range() */


char* reverseWords(char* s) {
    int length = skip_spaces(s);
    reverse_range(s, 0, length - 1);
    int start = 0;
    int end = 0;
    while (end <= length) {
        // detected word at [start, end)
        if ((end == length) || (s[end] == ' ')) {
            reverse_range(s, start, end - 1);
            start = end + 1;
        }
        end++;
    }
    return s;
}
