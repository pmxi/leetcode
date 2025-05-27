void reverse_range(char *, int, int);
int compress(char *, int);

/*
 * Modify s such that the substring [l, r) appears in reverse order.
 */

void reverse_range(char *s, int l, int r) {
    // adjust r according to half-open interval.
    r--;
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
} /* reverse_range(char *, int, int) */

/*
 * Leetcode 443 - string compression
 * optimized solution
 */

int compress(char* chars, int n) {
    if (n == 0) {
        return 0;
    }
    int write = 0;
    int run_length = 1;
    for (int i = 1; i <= n; i++) {
        if ((i < n) && (chars[i] == chars[i-1])) {
            run_length++;
        }
        // new group
        // we must write the appropriate text for the previous string.
        else {
            chars[write++] = chars[i-1];
            // only write repetitions if greater than 1
            if (run_length > 1) {
                int start = write;
                while (run_length > 0) {
                    chars[write++] = (run_length % 10) + '0';
                    run_length /= 10;
                }
                reverse_range(chars, start, write);
            }
            run_length = 1;
        }
    }
    return write;
} /* int compress(char *, int) */
