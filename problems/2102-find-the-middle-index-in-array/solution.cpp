class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int l = 0;
        int r = std::accumulate(nums.begin(), nums.end(), 0);
        for (int x = 0; x < nums.size(); x++) {
            int curr = nums[x];
            r -= curr;
            if (l == r) {
                return x;
            }
            l += curr;
        }
        return -1;
    }
};