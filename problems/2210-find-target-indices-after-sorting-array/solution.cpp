class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> out;
        for (int x = 0; x < nums.size(); x++) {
            if (nums[x] == target) {
                out.push_back(x);
            }
        }
        return out;
    }
};