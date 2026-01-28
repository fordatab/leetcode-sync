class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;        
        queue<int> q; // queue of route indices
        unordered_set<int> visitedRoutes;
        unordered_set<int> visitedStops;
        // Build stop -> routes mapping (O(total_stops))
        unordered_map<int, vector<int>> stopToRoutes;
        for (int routeId = 0; routeId < routes.size(); routeId++) {
            for (int stop : routes[routeId]) {
                stopToRoutes[stop].push_back(routeId);
            }
        }
        // Start with all routes containing source
        for (int route : stopToRoutes[source]) {
            q.push(route);
            visitedRoutes.insert(route);
        }
        int level = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int route = q.front(); q.pop();
                
                // Check if this route contains target
                if (find(routes[route].begin(), routes[route].end(), target) != routes[route].end()) {
                    // found answer
                    return level;
                }
                
                // Add all routes that share stops with current route
                for (int stop : routes[route]) {
                    if (visitedStops.count(stop)) continue;
                    visitedStops.insert(stop);
                    
                    for (int nextRoute : stopToRoutes[stop]) {
                        if (!visitedRoutes.count(nextRoute)) {
                            visitedRoutes.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }

            level++;
        }
        return -1;
    }
};