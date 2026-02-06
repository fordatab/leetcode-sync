class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1e9 + 7;
        
        // Collect all x-coordinates (edges)
        vector<int> xs;
        for (auto& r : rectangles) {
            xs.push_back(r[0]);
            xs.push_back(r[2]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        
        long long answer = 0;
        
        // Sweep through consecutive x intervals
        for (int i = 0; i + 1 < xs.size(); ++i) {
            int x1 = xs[i], x2 = xs[i + 1];
            
            // Collect all y-intervals active in [x1, x2)
            vector<pair<int,int>> intervals;
            for (auto& r : rectangles) {
                if (r[0] <= x1 && x2 <= r[2]) {
                    intervals.push_back({r[1], r[3]});
                }
            }
            
            // Merge overlapping y-intervals to get covered height
            sort(intervals.begin(), intervals.end());
            long long coveredY = 0;
            int curLo = -1, curHi = -1;
            for (auto& [lo, hi] : intervals) {
                if (lo >= curHi) {
                    coveredY += curHi - curLo;
                    curLo = lo;
                    curHi = hi;
                } else {
                    curHi = max(curHi, hi);
                }
            }
            coveredY += curHi - curLo;
            
            answer = (answer + coveredY % MOD * ((x2 - x1) % MOD)) % MOD;
        }
        
        return (int)answer;
    }
};