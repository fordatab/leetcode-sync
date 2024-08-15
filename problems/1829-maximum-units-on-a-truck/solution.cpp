class Solution {
public:
    int maximumUnits(vector<vector<int>>& vec, int truckSize) {
        sort(begin(vec), end(vec), 
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        int out = 0;
        int i = 0;
        while (truckSize > 0 && i < vec.size()) {
            int n = min(truckSize, vec[i][0]);
            out += n * vec[i][1];
            vec[i][0]-=n;
            if (vec[i][0] == 0) {
                i++;
            }
            truckSize -= n;
        }
        return out;
    }
};