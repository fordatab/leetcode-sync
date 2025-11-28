class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> inDeg(n + 1);
        inDeg[0] = -1;
        queue<int> q;
        vector<vector<int>> adj(n + 1, vector<int>());


        for (auto v : relations) {
            inDeg[v[1]]++;
            cout << inDeg[v[1]] << endl;
            adj[v[0]].push_back(v[1]);
        }
        vector<bool> visited(n+1);
        visited[0] = true;
        int iters = 0;
        for (int x = 1; x < n + 1; x++) {
            if (inDeg[x] == 0) {
                q.push(x);
                cout << "d" << endl;
            }
        }
        while (q.size()) {
            int s = q.size();
            while (s--) {
                int curr = q.front();
                q.pop();
                cout << curr << endl;
                visited[curr] = true;

                for (int node : adj[curr]) {
                    if (--inDeg[node]  == 0) {
                        q.push(node);
                    }
                }
            }
            iters++;
        }
        cout << endl;
        for (bool b : visited) {
            cout << b << endl;
            if (!b) {
                return -1;
            }
        }
        return iters;
    }
};