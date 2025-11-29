class Solution {
public:
    void dfs(set<pair<int, int>>& visited, 
            unordered_map<int, vector<int>>& h, unordered_map<int, vector<int>>& v, pair<int, int> curr) {
        if (visited.find(curr) != visited.end()) {
            return;
        }
        visited.insert(curr);
        for (auto a : h[curr.first]) {
            dfs(visited, h, v, {curr.first, a});
        }
        for (auto a : v[curr.second]) {
            dfs(visited, h, v, {a, curr.second});
        }

    }
    int removeStones(vector<vector<int>>& stones) {
        set<pair<int, int>> visited; 
        unordered_map<int, vector<int>> h;
        unordered_map<int, vector<int>> v;
        for (auto stone : stones) {
            h[stone[0]].push_back(stone[1]);
            v[stone[1]].push_back(stone[0]);
        } 
        int clusters = 0;
        for (auto stone : stones) {
            if (visited.find({stone[0], stone[1]}) == visited.end()) {
                clusters++;
                dfs(visited, h, v, {stone[0], stone[1]}); 
            }
        }
        return stones.size() - clusters;
        
    }
};