class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int sum = 0;
        int out = INT_MAX;
        while (r < nums.size()) {
            if (sum < target) {
                sum += nums[r++];
                // r++;
            } else if (sum == target) {
                out = min(out, r - l);
                sum += nums[r++];


            } else {
                out = min(out, r - l );
                sum -= nums[l++];
            }
            cout << sum << " " << l << " " << r << endl;

        }
        while (sum >= target) {
                            out = min(out, r - l );

            sum -= nums[l++];
        }
        return out == INT_MAX ? 0 : out;
    }
};