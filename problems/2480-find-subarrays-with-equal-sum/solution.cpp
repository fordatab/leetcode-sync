class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int, int> m;
        int a = nums[0];
        for (int x = 1; x < nums.size(); x++) {
            a += nums[x];
            m[a]++;
            if (m[a] == 2) {
                return true;
            }
            a -= nums[x-1];
        }
        return false;
    }
};