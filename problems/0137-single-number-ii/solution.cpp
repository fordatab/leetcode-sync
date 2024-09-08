class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int o = 0;
        int t = 0;
        for (int a : nums) {
            o = (o ^ a) & ~t;
            t = (t ^ a) & ~o;
        } 
        return o;
    }
};