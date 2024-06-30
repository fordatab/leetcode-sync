class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        int l = 0, r = 0;
        for (int x = 0; nums[x] <= 0 && x < nums.size()-2; x++) {
            if (x > 0) {
                if (nums[x] == nums[x-1]) {
                    continue;
                }
            }
            int target = 0 - nums[x];
            l = x + 1;
            r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    out.push_back({nums[x], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r-1] && l < r) {
                        r--;
                    }   
                }
                if (nums[l] + nums[r] < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return out;
    }
};
