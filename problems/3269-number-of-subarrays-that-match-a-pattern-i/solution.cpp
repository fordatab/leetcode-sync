class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int window_size = pattern.size() + 1; 
        int out = 0; 
        for (int x = 0; x < nums.size() - window_size + 1; x++) {
            int prev = nums[x];
            bool found = true;
            for (int y = 0; y < pattern.size(); y++) {
                if (pattern[y] == 1) {
                    if (nums[x + y + 1] > prev) {
                        prev = nums[x + y + 1];
                    } else {
                        found = false;
                        break;
                    }
                } else if (pattern[y] == 0) {
                    if (nums[x + y + 1] == prev) {
                        prev = nums[x + y + 1];
                    } else {
                        found = false;
                        break;
                    }
                } else {
                    if (nums[x + y + 1] < prev) {
                        prev = nums[x + y + 1];
                    } else {
                        found = false;
                        break;
                    }
                }
            }
            // cout << x << " " << found << endl;
            out += found;
        }
        return out;
    }
};