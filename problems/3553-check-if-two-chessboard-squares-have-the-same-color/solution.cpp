class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        if (c1[0] % 2 == c2[0] %2) {
            if (c1[1] %2 == c2[1] %2) {
                return true;
            } 
        } else {
            if (c1[1] %2 != c2[1] %2) {
                return true;
            } 
        }
        return false;
    }
};