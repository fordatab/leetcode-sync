class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l = 0;
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return strs[0].substr(0, l); 
                }
            }
            l++;
        }
        return strs[0].substr(0, l);
    }
};