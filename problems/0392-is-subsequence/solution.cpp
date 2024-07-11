class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;  // Early return for empty s
        
        int i = 0;
        for (char c : t) {
            if (c == s[i]) {
                i++;
                if (i == s.size()) return true;  // Early return when all of s is matched
            }
        }
        return false;  // s is not a subsequence of t
    }
};