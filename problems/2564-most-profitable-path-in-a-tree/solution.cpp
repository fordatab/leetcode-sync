class Solution {
public:
    // DFS to find Bob's path to 0 and record arrival times
    bool dfs(int curr, int target, vector<vector<int>>& adj, vector<int>& bobTime, int time) {
        bobTime[curr] = time; // Mark arrival time

        if (curr == target) {
            return true;
        }

        for (int neighbor : adj[curr]) {
            // If bobTime is INT_MAX, it means we haven't visited this node in this DFS path yet
            if (bobTime[neighbor] == INT_MAX) {
                if (dfs(neighbor, target, adj, bobTime, time + 1)) {
                    return true;
                }
            }
        }

        // BACKTRACK: If this path didn't lead to 0, reset time to Infinity
        bobTime[curr] = INT_MAX; 
        return false;
    }

    // DFS for Alice to find max score
    void find(int curr, vector<vector<int>>& adj, vector<int>& visited, vector<int>& bobTime, int time, int currentScore, int& maxScore, vector<int>& amount) {
        visited[curr] = 1;

        // 1. Calculate Score at this node based on Bob's arrival
        if (time < bobTime[curr]) {
            currentScore += amount[curr]; // Alice first
        } else if (time == bobTime[curr]) {
            currentScore += amount[curr] / 2; // Tie
        } 
        // If time > bobTime[curr], score + 0 (Alice late)

        // 2. Check if Leaf (no unvisited neighbors)
        bool isLeaf = true;
        for (int neighbor : adj[curr]) {
            if (visited[neighbor] == 0) {
                isLeaf = false;
                find(neighbor, adj, visited, bobTime, time + 1, currentScore, maxScore, amount);
            }
        }

        // 3. Update global max if it's a leaf
        if (isLeaf) {
            maxScore = max(maxScore, currentScore);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        
        for (auto& v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        // Initialize bobTime to INT_MAX so unvisited nodes are "infinity"
        vector<int> bobTime(n, INT_MAX);
        
        // Find Bob's path and fill times
        dfs(bob, 0, adj, bobTime, 0);

        // Run Alice's traversal
        int maxScore = INT_MIN;
        vector<int> visited(n, 0);
        
        // Pass currentScore=0 to start
        find(0, adj, visited, bobTime, 0, 0, maxScore, amount);

        return maxScore;
    }
};