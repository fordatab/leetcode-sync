class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for (int x : arr) {
            m[x]++;
        }
        unordered_set<int> s;
        for (auto a : m) {
            s.insert(a.second);
        }
        return s.size() == m.size();
    }
};