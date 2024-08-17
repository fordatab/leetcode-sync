class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<vector<int>> out = {intervals[0]};
        int l = INT_MAX;
        int r = 0;
        for (int x = 0; x < intervals.size(); x++) {
            if (intervals[x][0] <= out.back()[1]) {
                out.back()[1] = max(intervals[x][1], out.back()[1]);
            } else {
                out.push_back(intervals[x]);
            }
        }
        return out;
    }
};