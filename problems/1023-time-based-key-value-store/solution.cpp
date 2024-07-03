class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> map;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) {
            return "";
        }

        if (map[key][0].second > timestamp) {
            return "";
        }


        int l = 0;
        int r = map[key].size() - 1;
        while (l <= r) {
            int mid = (r - l)/2 + l;
            if (map[key][mid].second == timestamp) {
                return map[key][mid].first;
            }
            if (map[key][mid].second > timestamp) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return map[key][r].first;
    }
};
