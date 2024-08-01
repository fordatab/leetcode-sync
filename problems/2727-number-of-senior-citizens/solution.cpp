class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c = 0;
        for (string s : details) {
            if (s[11] >= '6') {
                if (s[11] == '6') {
                    if (s[12] > '0') {
                        c++;
                    }
                } else {
                    c++;
                }
            }
        }
        return c;
    }
};