class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        unordered_set<int> s;
        for (r; r < nums.size(); r++) {
            // cout << l << " " << r << endl;
            if (r - l > k) {
                s.erase(nums[l++]);
            }
            if (s.find(nums[r]) != s.end()) {
                return true;
            }
            s.insert(nums[r]);
        }
        return false;

    }
};