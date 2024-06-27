class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int x = 0; x < nums.size(); x++) {
            int comp = target - nums[x];
            if (m.find(comp) == m.end()) {
                m[nums[x]] = x;
            } else {
                return vector<int> {m[comp], x};
            }
        }
        return {};
    }
};