/*
 * This is optimal when testing only one s.
 * This solution isn't optimal with many incoming s,
 * as per the follow up.
 */

bool isSubsequence(char* s, char* t) {
    for (; *s && *t ; t++) {
        if (*s == *t) {
            s++;
        }
    }
    return (*s == '\0');
} /* isSubsequence(char *, char *) */
