class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0); // 0: unvisited, 1: visiting, 2: visited
        vector<int> out;
        for (const auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        bool cycle = true;
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(adj, i, visited, out)) {
                cycle = false;
            }
        }
        
        if (cycle) {
            return out;
        } else {
            return {};
        }
    }
private:
    bool hasCycle(const vector<vector<int>>& adj, int node, vector<int>& visited, vector<int>& o) {
        if (visited[node] == 1) return true;  // Cycle detected
        if (visited[node] == 2) return false; // Already visited, no cycle
        
        visited[node] = 1; // Mark as visiting
        
        for (int neighbor : adj[node]) {
            if (hasCycle(adj, neighbor, visited, o)) {
                return true;
            }
        }
        o.push_back(node);
        visited[node] = 2; // Mark as visited
        return false;
    }
};


