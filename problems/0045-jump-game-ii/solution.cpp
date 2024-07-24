class Solution {
public:
    int jump(vector<int>& nums) {
        int out = 0;
        int l = 0; 
        int r = 0;
        while (r < nums.size() - 1) {
            int m = 0;
            for (int x = l; x <= r; x++) {
                m = max(m, x + nums[x]);
            }
            l = r + 1;
            r = m;
            out++;
        }
        return out;
    }
};
