class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> l(26);
        for (auto c : magazine) {
            l[c-'a']++;
        }
        for (auto c : ransomNote) {
            l[c-'a']--;
        }
        for (auto i : l) {
            if (i < 0) {
                return false;
            }
        }
        return true;
    }
};