class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for (string t : timePoints) {
            int hour = stoi(t.substr(0, 2));
            int mins = stoi(t.substr(3, 2));
            times.push_back(60*hour + mins);
        }
        for (int x : times) {
            cout << x << " "; 
        }
        sort(times.begin(), times.end());
        int out = INT_MAX;
        for (int x = 0; x < times.size(); x++) {
            if (x == times.size() - 1) {
                out = min(out, 1440 - (times[x] - times[0]));
            } else {
                out = min(out, times[x+1] - times[x]);
            }
        }
        return out;
    }
};