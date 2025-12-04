class Solution {
public:
bool check(vector<int>& times) {
    for (int i = 0; i + 2 < times.size(); i++) {
        if (times[i + 2] - times[i] <= 60) {
            return true;  // Found 3 accesses within 60 minutes
        }
    }
    return false;  // No alert triggered
}
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> m;
        for (int x = 0; x < keyName.size(); x++) {
            int time = stoi(keyTime[x].substr(0, 2)) * 60 + stoi(keyTime[x].substr(3, 2));
            m[keyName[x]].push_back(time);
        }
        for (auto& [a, b] : m) {
            sort(b.begin(), b.end());
        }
        vector<string> out;
        for (auto [a, b] : m) {
            if (check(b)) {
                out.push_back(a);
            }
        }
        
        sort(out.begin(), out.end());
        return out;
    }
};