class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        vector<int> out;
        while (out.size() != nums.size()) {
            if (abs(nums[l]) < abs(nums[r])) {
                out.push_back(nums[r]*nums[r]);
                r--;
            } else {
                out.push_back(nums[l]*nums[l]);
                l++;
            }
        }
        reverse(begin(out), end(out));
        return out;
    }
};