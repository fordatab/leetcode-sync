class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        vector<vector<int>> out;
        int i = 0;
        int j = 0;
        while (i < fl.size() && j < sl.size()) {
            if (fl[i][1] < sl[j][0]) {
                i++;
            } else if (sl[j][1] < fl[i][0]) {
                j++;
            } else {
                if (fl[i][1] < sl[j][1]) {
                    out.push_back({max(fl[i][0], sl[j][0]), fl[i][1]});
                    i++;
                } else {
                    out.push_back({max(fl[i][0], sl[j][0]), sl[j][1]});
                    j++;
                }
            }
        }
        return out;
    }
};