class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int b_ct = 0;
        int pre = 0;
        for (char & x : s) {
            if (x == '0') {
                pre = min(pre + 1, b_ct);
            } else {
                b_ct++;
            }
        }
        return pre;
    }
};

