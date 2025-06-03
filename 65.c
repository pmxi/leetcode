// I will implement a discrete finite-state automaton
// figuring out the DFA is a hassle
// but workable with pen and paper

// implementing a DFA is a rare opportunity to get away with using goto


bool isNumber(char* s) {
    char c;
s0:
    c = *s++;
    if (c == '+' || c == '-') goto s2;
    if (c == '.') goto s3;
    if (isdigit(c)) goto s1;
    // return false if ending here (s0 is a non-accepting state)
    // return false if illegal char
    return false;
s1:
    c = *s++;
    if (isdigit(c)) goto s1;
    if (c == '.') goto s4;
    if (c == 'e' || c == 'E') goto s5;
    // this is an accepting state
    if (c == '\0') return true;
    return false;
s2:
    c = *s++;
    if (isdigit(c)) goto s1;
    if (c == '.') goto s3;
    return false;
s3:
    c = *s++;
    if (isdigit(c)) goto s4;
    return false;
s4:
    c = *s++;
    if (isdigit(c)) goto s4;
    if (c == 'e' || c == 'E') goto s5;
    if (c == '\0') return true;
    return false;
s5:
    c = *s++;
    if (c == '+' || c == '-') goto s6;
    if (isdigit(c)) goto s7;
    return false;
s6:
    c = *s++;
    if (isdigit(c)) goto s7;
    return false;
s7:
    c = *s++;
    if (isdigit(c)) goto s7;
    if (c == '\0') return true;
    return false;
}
