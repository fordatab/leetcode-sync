class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(begin(points), end(points));
        int m = INT_MIN;
        for (int x = 1; x < points.size(); x++) {
            m = max(points[x][0] - points[x-1][0], m);
        }
        return m;
    }
};