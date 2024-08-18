class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int r_prev = intervals[0][1];
        int out = 0;
        for (int x = 1; x < intervals.size(); x++) {
            if (r_prev > intervals[x][0]) {
                out++;
                r_prev = min(intervals[x][1], r_prev);
            } else {
                r_prev = intervals[x][1];
            }
        }
        return out;
    }
};
