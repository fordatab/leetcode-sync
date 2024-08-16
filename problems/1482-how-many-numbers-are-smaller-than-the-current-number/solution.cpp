class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> b(101);
        for (auto x : nums) {
            b[x]++;
        }
        vector<int> r(101);
        int sum = 0;
        for (int x = 0; x < 101; x++) {
            sum += b[x];
            r[x] = sum;
        }
        vector<int> out(nums.size());
        for (int x = 0; x < nums.size(); x++) {
            out[x] = r[nums[x]] - b[nums[x]];
        }
        return out;
    }
};