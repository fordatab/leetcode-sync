class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long coverage = 0;  // can cover [1..coverage]
        int patches = 0;
        int i = 0;

        while (coverage < n) {
            if (i < nums.size() && nums[i] <= coverage + 1) {
                // nums[i] extends coverage
                coverage += nums[i];
                i++;
            } else {
                // need a patch equal to coverage+1
                patches++;
                coverage += coverage + 1;
            }
        }

        return patches;
    }
};
