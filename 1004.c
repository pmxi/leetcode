// we use a sliding window
// constraint: number of zeroes <= k
// if constraint is satisfied, increment right pointer
// if violated, increment left pointer


int longestOnes(int* nums, int numsSize, int k) {
    int l = 0;
    int num_zeroes = 0;
    int max_len = 0;
    
    // our window is [l, r]
    for (int r = 0; r < numsSize; r++) {
        num_zeroes += nums[r] == 0;
        while (num_zeroes > k) {
            num_zeroes -= nums[l] == 0;
            l++;
        }
        // invariant: [l, r] is valid.
        int len = r - l + 1;
        if (len > max_len) max_len = len;
    }
    return max_len;
}
