class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for (int x = 0; x < word1.size(); x++) {
            m1[word1[x]-'a']++;
            m2[word2[x]-'a']++;
        }
        if (m1 == m2) {
            return true;
        }
        unordered_map<int,int> c1;
        unordered_map<int,int> c2;
        for (auto a : m1) {
            c1[a.second]++;
        }
        for (auto a : m2) {
            c2[a.second]++;
        }

        for (auto a : m1) {
            if (m2.find(a.first) == end(m2)) {
                return false;
            }
        }
        if (c1 == c2) {
            return true;
        }
        return false;
    }
};