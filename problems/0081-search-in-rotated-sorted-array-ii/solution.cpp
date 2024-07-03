class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (auto a : nums) {
            if (target == a) {
                return true;
            }
        }
        return false;
    }
};