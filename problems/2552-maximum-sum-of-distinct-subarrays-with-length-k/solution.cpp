class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long out = 0;
        int l = 0;
        unordered_map<int, int> s;
        long long sum = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            s[nums[r]]++;
            // cout << r - l + 1 << endl;
            if (r - l + 1 == k) {
                // cout << s.size() << endl;
                if (s.size() == k) {
                    out = max(out, sum);
                }
                sum -= nums[l];
                s[nums[l]]--;
                if (s[nums[l]] == 0) {
                    s.erase(nums[l]);
                }
                l++;
            }

        }
        return out;
    }
};