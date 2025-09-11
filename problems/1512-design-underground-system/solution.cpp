class UndergroundSystem {
public:
// map each customer to their starting station and start time 
    unordered_map<int, pair<string, int>> customers;
        // map each start -> end stations with times

    map<string, map<string, vector<pair<int, int>>>> m; 
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customers[id] = {stationName, t};
    }
    
    void checkOut(int id, string endStation, int t) {
        auto start_station = customers[id];
        m[start_station.first][endStation].push_back({start_station.second, t});
        customers.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int n = m[startStation][endStation].size();
        int sum = 0;
        for (auto [s, e] : m[startStation][endStation]) {
            sum += e - s;
        }
        return (double)sum/n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */