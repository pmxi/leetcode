int pivotIndex(int *nums, int numsSize) {

    int left = 0;
    int right = 0;

    // initialize right sum
    for (int i = 0; i < numsSize; i++) {
        right += nums[i];
    }

    for (int pivot = 0; pivot < numsSize; pivot++) {
        right -= nums[pivot];
        if (left == right) {
            return pivot;
        }
        left += nums[pivot];
    }

    // no pivot exists
    return -1;
}
