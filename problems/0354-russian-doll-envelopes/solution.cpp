class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    }


    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        // for (auto v : envelopes) {
        //     cout << v[0] << " " << v[1] << endl;
        // }
        vector<int> lis;
        for (auto v : envelopes) {
            if (lis.empty()) {
                lis.push_back(v[1]);

                
            } else {
                auto it = lower_bound(lis.begin(), lis.end(), v[1]);
                if (it == lis.end()) {
                    lis.push_back(v[1]);
                } else {
                    *it = v[1];
                }

            }
        }
        return lis.size();
        
    }
};