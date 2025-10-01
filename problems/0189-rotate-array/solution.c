#include <stdio.h>

// helper: reverse array between indices l and r inclusive
void reverse(int* nums, int l, int r) {
    while (l < r) {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        l++;
        r--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0) return;
    k %= numsSize;
    if (k == 0) return;

    // 1. reverse whole array
    reverse(nums, 0, numsSize - 1);
    // 2. reverse first k elements
    reverse(nums, 0, k - 1);
    // 3. reverse remaining n-k elements
    reverse(nums, k, numsSize - 1);
}
