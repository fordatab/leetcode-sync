class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = INT_MAX;
        int diff = INT_MAX; 
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;
            int newTarget = target - nums[i];
            while (l < r) {
                if (abs(newTarget - (nums[l] + nums[r])) < diff) {
                    diff = abs(newTarget - (nums[l] + nums[r]));
                    closest = nums[i] + nums[l] + nums[r];
                }
                if (nums[l] + nums[r] <= newTarget) {
                    l++;
                } else {
                    r--;
                }
            } 
        } 
        return closest;
    }
};