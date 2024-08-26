class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> out;
        for (int x = 0; x < nums.size(); x+=2) {
            for (int y = 0; y < nums[x]; y++) {
                out.push_back(nums[x+1]);
            }
        }
        return out;
    }
};