class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int out = 0;
        for (int n : nums) {
            int d = 0;
            while (n) {
                n/=10;
                d++;
            }
            if (d %2 == 0) {
                out ++;
            }
        }
        return out;
    }
};