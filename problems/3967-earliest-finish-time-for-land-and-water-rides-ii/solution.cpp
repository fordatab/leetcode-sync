class Solution {
public:
    int solve(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int finish1 = INT_MAX;
        for (int i = 0; i < ls.size(); i++) {
            finish1 = min(finish1, ls[i] + ld[i]);
        }

        int out = INT_MAX;
        for (int j = 0; j < ws.size(); j++) {
            out = min(out, max(finish1, ws[j]) + wd[j]);
        }
        return out;
    }

    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {

        return min(solve(ls, ld, ws, wd), solve(ws, wd, ls, ld));
    }
};