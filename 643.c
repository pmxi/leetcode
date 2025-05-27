double findMaxAverage(int* nums, int numsSize, int k) {
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    long long max_sum = sum;
    for (int j = k; j < numsSize; j++) {
        sum += nums[j] - nums[j - k];
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    return (double) max_sum / k;
}
