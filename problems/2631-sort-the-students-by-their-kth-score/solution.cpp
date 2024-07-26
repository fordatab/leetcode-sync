class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<pair<int, int>> v;
        for (int x = 0; x < score.size(); x++) {
            v.push_back({score[x][k], x});
        }
        sort(rbegin(v), rend(v));
        vector<vector<int>> out;
        for (auto [a, b] : v) {
            out.push_back(score[b]);
        }
        return out;
    }
};