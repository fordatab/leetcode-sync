class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        for (const auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }
        
        vector<string> route;
        dfs("JFK", adj, route);
        reverse(route.begin(), route.end());
        return route;
    }

private:
    void dfs(const string& airport, unordered_map<string, multiset<string>>& adj, vector<string>& route) {
        while (!adj[airport].empty()) {
            string next = *adj[airport].begin();
            adj[airport].erase(adj[airport].begin());
            dfs(next, adj, route);
        }
        route.push_back(airport);
    }
};