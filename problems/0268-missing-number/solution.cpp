class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> n(nums.begin(), end(nums));
        for (int x = 0; x < nums.size()+1; x++) {
            if (n.find(x) == end(n)) {
                return x;
            }
        }
        return -1;
    }
};