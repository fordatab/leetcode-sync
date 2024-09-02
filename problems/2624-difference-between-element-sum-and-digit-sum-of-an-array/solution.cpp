class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int out = 0;
        for (int n : nums) {
            out += n;
            while (n) {
                out -= n%10;
                n/=10;
            }
        }
        return abs(out);
    }
};