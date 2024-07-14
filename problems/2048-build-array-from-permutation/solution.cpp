class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> out;
        for (int x = 0; x < nums.size(); x++) {
            out.push_back(nums[nums[x]]);
        }
        return out;
    }
};