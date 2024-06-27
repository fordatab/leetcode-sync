class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> m;
        for (auto a : strs) {
            string sorted = a;
            sort(sorted.begin(), sorted.end());
            if (m.find(sorted) != m.end()) {
                m[sorted].push_back(a);
            } else {
                m[sorted].push_back(a);
            }
        }
        vector<vector<string>> out;
        for (auto a : m) {
            out.push_back(a.second);
        }
        return out;
    }
};
