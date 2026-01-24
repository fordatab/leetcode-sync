class Solution {
private:
    vector<vector<pair<int, int>>> graph;
    vector<int> answer;
    
    void dfs1(int node, int parent) {
        for (auto [child, cost] : graph[node]) {
            if (child == parent) continue;
            answer[0] += cost;
            dfs1(child, node);
        }
    }
    
    void dfs2(int node, int parent) {
        for (auto [child, cost] : graph[node]) {
            if (child == parent) continue;
            answer[child] = answer[node] - cost + (1 - cost);
            dfs2(child, node);
        }
    }
    
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        // Build graph as member variable
        graph.resize(n);
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], 0}); // original direction - no reversal
            graph[e[1]].push_back({e[0], 1}); // reverse direction - needs reversal
        }
        
        answer.assign(n, 0);
        
        dfs1(0, -1);
        dfs2(0, -1);
        
        return answer;
    }
};