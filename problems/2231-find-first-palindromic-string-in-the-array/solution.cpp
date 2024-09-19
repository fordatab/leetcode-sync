class Solution {
public:
    bool is_pali(string& str) {
        int r = str.size() - 1;
        int l = 0;
        while (l < r) {
            if (str[r--] != str[l++]) {
                return false;
            }
        } 
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (string & str : words) {
            if (is_pali(str)) {
                return str;
            }
        }
        return "";
    }
};