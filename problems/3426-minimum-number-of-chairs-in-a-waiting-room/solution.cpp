class Solution {
public:
    int minimumChairs(string s) {
        int out = 0;
        int m = 0; 
        for (char c : s) {

            if (c == 'E') {
                out ++;
            } else {
                out--;
            }
            m = max(m, out);
        }
        return m;
    }
};