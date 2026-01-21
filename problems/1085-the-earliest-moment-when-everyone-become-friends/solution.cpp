class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // Sort logs by timestamp
        sort(logs.begin(), logs.end());
        
        // Initialize Union-Find
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int components = n; // Initially each person is their own component
        
        // Union-Find helper functions
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        };
        
        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                // Union by rank
                if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
                components--; // Two components merged into one
                return true;
            }
            return false;
        };
        
        // Process logs in chronological order
        for (auto& log : logs) {
            int timestamp = log[0];
            int person1 = log[1];
            int person2 = log[2];
            
            unite(person1, person2);
            
            // When all people are connected, we have one component
            if (components == 1) {
                return timestamp;
            }
        }
        
        return -1; // Impossible to connect everyone
    }
};