class Solution {
public:
    bool doesAliceWin(string s) {
        int ct = 0;
        for (char c : s) {
            if (c =='a' || c =='e' || c =='i' || c =='o' || c =='u') {
                ct++;
            }
        }
        if (ct % 2) {
            return true;
        }
        if (ct == 0) {
            return false;
        }



        // acacaca
        return true;
    }
};