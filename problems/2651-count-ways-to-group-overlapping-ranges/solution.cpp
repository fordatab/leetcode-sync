class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<vector<int>> out = {intervals[0]};

        for (auto& interval : intervals) {
            if (interval[0] <= out.back()[1]) {
                out.back()[1] = max(interval[1], out.back()[1]);
            } else {
                out.push_back(interval);
            }
        }
        return out;
    }

    int modular_pow(int base, int exponent,int modulus) {
        if (modulus == 1) {
            return 0;
        }
        int c = 1;
        for (int e = 0; e < exponent; e++) {
            c = (c * base) % modulus;

        }
        return c;
    }


    int countWays(vector<vector<int>>& ranges) {
        ranges = merge(ranges);
        // cout << ranges.size();
        int MOD = 1e9 + 7;
        return modular_pow(2, ranges.size(), MOD);
    }
};