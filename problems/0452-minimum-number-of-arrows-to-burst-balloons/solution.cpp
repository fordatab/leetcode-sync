class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points));
        int out = 0;
        int i = 0;
        for (i; i < points.size(); i++) {
            int arrow = points[i][1];
            while (i < points.size()-1 && arrow >= points[i+1][0]) {
                arrow = min(arrow, points[i+1][1]);
                                i++;

            }
            out++;
        }
        return out;
    }
};