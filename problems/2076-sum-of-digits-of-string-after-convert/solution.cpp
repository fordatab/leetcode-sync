class Solution {
public:
    int getLucky(string s, int k) {
        int out = 0;
        for (char c : s) {
            out += (c - 'a' + 1)%10;
            out += (c - 'a' + 1)/10;

        }
        while (--k) {
            int n = 0;
            while (out) {
                n += out%10;
                out /= 10;
            }
            out = n;
        }
        return out;
    }
};