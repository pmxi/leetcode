/*
 * Naive solution. Assume caller calls free().
 */

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *answer = malloc(sizeof(int) * numsSize);

    int product = 0;
    for (int i = 0; i < numsSize; i++) {
        product = 1;
        for (int j = 0; j < numsSize; j++) {
            if (i != j) {
                product *= nums[j];
            }
        }
        answer[i] = product;
    }
    *returnSize = numsSize;
    return answer;
} /* productExceptSelf() */




/*
 * Slightly better solution. Assume caller calls free().
 * space is O(n)
 * time is O(n)
 */

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *answer = malloc(sizeof(int) * numsSize);
    // Definitions:
    // prefix[i] is the product of
    // nums[0], nums[1], ... nums[i - 1]
    // suffix[i] is the product of
    // nums[i + 1], nums[i + 2], ... nums[numsSize - 1]
    int *prefix = malloc(sizeof(int) * numsSize);
    int *suffix = malloc(sizeof(int) * numsSize);

    // build prefix array
    // base case: the empty product
    prefix[0] = 1;
    // recursive property
    for (int i = 1; i < numsSize; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // build suffix array
    // base case: the empty product
    suffix[numsSize - 1] = 1;
    // recursive property
    for (int i = numsSize - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < numsSize; i++) {
        answer[i] = prefix[i] * suffix[i];
    }

    *returnSize = numsSize;
    return answer;
} /* productExceptSelf() */




/*
 * Best solution. Assume caller calls free().
 * space is O(1)
 * time is O(n)
 */

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *answer = malloc(sizeof(int) * numsSize);
    // Definitions:
    // prefix[i] is the product of
    // nums[0], nums[1], ... nums[i - 1]
    // suffix[i] is the product of
    // nums[i + 1], nums[i + 2], ... nums[numsSize - 1]

    // build prefix array
    // base case: the empty product
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    *returnSize = numsSize;
    return answer;
} /* productExceptSelf() */
