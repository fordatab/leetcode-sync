class Solution {
public:
    bool check(char a, char b) {
        if (a - b >= 0 and a - b < 2) {
            return true;
        } 
        if (a - b == -25) {
            return true;
        }
        return false;
    } 
    bool canMakeSubsequence(string str1, string str2) {
        // if (str2.size() < str1.size()) {
            swap(str2, str1);
        // }
        // cout << str2 << endl;
        int j = 0; 
        for (int i = 0; i < str1.size(); i++) {
            while (j < str2.size() and !check(str1[i], str2[j])) {
                j++;
            }
            if (j == str2.size()) {
                return false;
            }
            j++;
        }
        return true;
    }
};