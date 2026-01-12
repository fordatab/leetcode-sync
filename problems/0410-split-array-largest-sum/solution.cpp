class Solution {
public:
bool canSplit(vector<int>& nums, int k, long long maxSum) {
    long long currentSum = 0;
    int splits = 1; // number of subarrays needed
    
    for (int num : nums) {
        if (currentSum + num > maxSum) {
            splits++; // need a new subarray
            currentSum = num;
            if (splits > k) return false;
        } else {
            currentSum += num;
        }
    }
    return true;
}
int splitArray(vector<int>& nums, int k) {
    long long left = *max_element(nums.begin(), nums.end());
    long long right = accumulate(nums.begin(), nums.end(), 0LL);
    
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (canSplit(nums, k, mid)) {
            right = mid; // try smaller maximum sum
        } else {
            left = mid + 1; // need larger maximum sum
        }
    }
    return left;
}
};