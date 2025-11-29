class LogSystem {
public:
    // store (timestamp, id)
    vector<pair<string, int>> logs;
    
    LogSystem() {}

    void put(int id, string timestamp) {
        logs.push_back({timestamp, id});
    }

    vector<int> retrieve(string start, string end, string granularity) {
        int len = getLen(granularity);
        
        // truncate start & end according to granularity
        string s = start.substr(0, len);
        string e = end.substr(0, len);
        
        vector<int> res;
        for (auto &p : logs) {
            const string &t = p.first;
            string cur = t.substr(0, len);
            if (cur >= s && cur <= e) {
                res.push_back(p.second);
            }
        }
        return res;
    }

private:
    int getLen(const string &g) {
        if (g == "Year")   return 4;   // "YYYY"
        if (g == "Month")  return 7;   // "YYYY:MM"
        if (g == "Day")    return 10;  // "YYYY:MM:DD"
        if (g == "Hour")   return 13;  // "YYYY:MM:DD:HH"
        if (g == "Minute") return 16;  // "YYYY:MM:DD:HH:MM"
        return 19;                     // "YYYY:MM:DD:HH:MM:SS"
    }
};
