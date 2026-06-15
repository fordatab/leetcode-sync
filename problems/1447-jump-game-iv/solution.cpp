class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> map;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            map[arr[i]].push_back(i);
        }
        vis[0] = true;
        queue<int> q;
        q.push(0);
        int steps = 0;
        while (!q.empty()) {
            int level = q.size();
            while (level--) {
                int index = q.front();
                q.pop();
                vis[index] = true;
                if (index == n - 1) {
                    return steps;
                }
                if (index > 0) {
                    if (!vis[index-1]) {
                        q.push(index-1);
                    }
                }
                if (index < n - 1) {
                    if (!vis[index+1]) {
                        q.push(index+1);
                    }
                }
                if (map.find(arr[index]) != map.end()) {
                    for (auto i : map[arr[index]]) {
                        if (!vis[i]) {
                            q.push(i);
                        }
                    }
                    map.erase(arr[index]);
                } 
            }
            steps++;
        }
        return -1;
    }
};