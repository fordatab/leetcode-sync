/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for (int x = 0; x < numsSize; x++) {
        for (int y = 1; y < numsSize; y++) {
            if ((nums[x]+nums[y] == target) && (x!=y)) {
                returnSize = malloc(8);
                returnSize[0] = x;
                returnSize[1] = y;
                return returnSize;
            }
        }
    }
    return returnSize;
}