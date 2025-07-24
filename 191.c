// This page has compiled quite a few ways to count bits set.
// https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan


int hammingWeight(int n) {
    int set = 0;
    while (n) {
        // unset the lowest set bit
        // "Brian Kernigan's trick"
        n &= n - 1;
        set++;
    }
    return set;
}

// This is my original mediocre solution
// int hammingWeight(int n) {
//     int set = 0;
//     for (int i = 0; i < 32; i++) {
//         if (n & 1) set++;
//         n >>= 1;
//     }
//     return set;
// }
