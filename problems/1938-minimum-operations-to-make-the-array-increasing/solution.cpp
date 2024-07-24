class Solution {
public:
    int minOperations(vector<int>& nums) {
        int out = 0;
        for (int x = 1; x < nums.size(); x++) {
            // cout << nums[x] << " " << nums[x-1] << endl;
            if (nums[x] <= nums[x-1]) {
                int a = nums[x-1] - nums[x] + 1;
                nums[x] += a;
                out += a;
            }
        }
        return out;
    }
};