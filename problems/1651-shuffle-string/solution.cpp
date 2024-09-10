class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string tmp = s;
        for (int x = 0; x < s.size(); x++) {
            tmp[indices[x]] = s[x];
        } 
        return tmp;
    }
};