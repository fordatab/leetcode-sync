class Solution {
public:
    bool check(vector<int>& nums) {
        int i = 0;
        for (int x = 0; x < nums.size()-1; x++) {
            if (nums[x] > nums[x+1]) {
                i = x + 1;
                break;
            }
        }

        for (int x = i; x < i + nums.size() -1; x++) {
            if (nums[x%nums.size()] > nums[(x+1)%nums.size()]) {
                return false;
            }
        }

        return true;
    }
};