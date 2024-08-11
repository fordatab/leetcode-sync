class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        vector<bool> v(graph.size());
        dfs(0, paths, path, graph, v);
        return paths;
    }

    void dfs(int n, vector<vector<int>>& paths, vector<int>& path, vector<vector<int>>& graph, vector<bool>& v) {
        path.push_back(n);
        if (n == graph.size() - 1) {
            paths.push_back(path);
            path.pop_back();
            return;
        }
        v[n] = true;
        for (auto a : graph[n]) {
            dfs(a, paths, path, graph, v);
        }
        path.pop_back();
    }
};