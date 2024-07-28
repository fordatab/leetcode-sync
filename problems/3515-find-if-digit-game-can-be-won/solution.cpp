class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int t = 0;
        int s = 0;
        for (int x : nums) {
            if (x / 10 == 0) {
                s += x;
            } else {
                t += x;
            }
        }
        return t != s;
    }
};