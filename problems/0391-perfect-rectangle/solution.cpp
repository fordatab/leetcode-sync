class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> corners;
        int minx = INT_MAX;;
        int miny = INT_MAX;
        int maxx = INT_MIN;
        int maxy = INT_MIN;
        long long area = 0;
        for (auto r : rectangles) {
            minx = min(minx, r[0]);
            miny = min(miny, r[1]);
            maxx = max(maxx, r[2]);
            maxy = max(maxy, r[3]);
            corners[{r[0], r[1]}]++; // bl 
            corners[{r[2], r[3]}]++; // tr
            corners[{r[0], r[3]}]++; // tl
            corners[{r[2], r[1]}]++; // br
            area +=  ((long long) (r[2] - r[0])) * ((long long) (r[3] - r[1])); 
        }
        bool bl = false;
        bool tr = false;
        bool tl = false;
        bool br = false;
        pair<int, int> blCorner = {minx, miny};
        pair<int, int> trCorner = {maxx, maxy};
        pair<int, int> tlCorner = {minx, maxy};
        pair<int, int> brCorner = {maxx, miny};
        for (auto [p, ct] : corners) {
            if (p == blCorner and ct == 1) {
                bl = true;
                continue;
            }
            if (p == trCorner and ct == 1) {
                tr = true;
                                continue;

            }
            if (p == tlCorner and ct == 1) {
                tl = true;
                                continue;

            }
            if (p == brCorner and ct == 1) {
                br = true;
                                continue;

            }
            if (ct % 2 or ct > 4) {
                return false;
            }
        }
        return bl and tr and tl and br and (area == (long long)(maxx - minx) * (long long)(maxy - miny)); 
    }
};