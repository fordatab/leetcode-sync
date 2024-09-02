class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // a/b = 2;
        // b/c = 3;
        // b = a/2;
        // b = 3c
        // a/2 = 3c;.0
        // a/c = 6; 
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int x = 0; x < equations.size(); x++) {
            auto v = equations[x];

            adj[v[0]].push_back({v[1], values[x]});
            adj[v[1]].push_back({v[0], 1/values[x]});
            adj[v[0]].push_back({v[0], 1});
            adj[v[1]].push_back({v[1], 1});



        }
        vector<double> out;
        unordered_set<string> visited;
        for (auto v : queries) {
            cout << v[0] << endl;
            out.push_back(dfs(adj, v[0], v[1], visited));
            visited.clear();
        }
        return out;
    }

    double dfs(unordered_map<string, vector<pair<string, double>>>& adj, string start, string end, unordered_set<string>& v) {
        if (adj.find(start) == adj.end() || adj.find(end) == adj.end()) {
            cout << "a" << endl;
            return -1.0;
        }

        v.insert(start);
        for (auto vec : adj[start]) {
            if (vec.first == end) {
                return vec.second;
            }
            if (!v.contains(vec.first)) {
                double prod = dfs(adj, vec.first, end, v);
                if (prod != -1.0) {
                    return prod * vec.second;
                }
            }
        }
        return -1.0;
    }
};