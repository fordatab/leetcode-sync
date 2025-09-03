class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> s;
        int out = INT_MAX;
        int n = nums.size();

        for (int i = x; i < n; i++) {
            s.insert(nums[i - x]); // element becomes eligible now

            auto it = s.lower_bound(nums[i]);
            if (it != s.end()) {
                out = min(out, abs(*it - nums[i]));
            }
            if (it != s.begin()) {
                --it;
                out = min(out, abs(*it - nums[i]));
            }
        }

        return out; 
    }
};
