int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int b[101] = {0};  // Initialize all elements to 0
    int i;

    // Count occurrences
    for (i = 0; i < numsSize; i++) {
        b[nums[i]]++;
    }

    // Calculate cumulative counts
    for (i = 1; i < 101; i++) {
        b[i] += b[i-1];
    }

    // Update nums array with smaller counts
    for (i = 0; i < numsSize; i++) {
        if (nums[i]) {
            nums[i] = b[nums[i] - 1];
        }
    }

    *returnSize = numsSize;
    return nums;
}