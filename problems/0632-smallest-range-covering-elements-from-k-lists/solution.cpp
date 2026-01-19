class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> out;
        int sum = 0;
        for (auto n : nums) {
            sum += n.size();
        }
        vector<pair<int, int>> all;
        int l = 0;
        for (auto n : nums) {
            for (int x : n) {
                all.push_back({x, l});
            }
            l++;
        }
        sort(all.begin(), all.end());
        unordered_map<int, int> m;
        l = 0;
        int ct = 0;
        int start = 0;
        int end = INT_MAX;
        for (int i = 0; i < sum; i++) {
            
            if (++m[all[i].second] == 1) {
                ct++;
            }

            while (ct == nums.size()) {
                int range = all[i].first - all[l].first;
                if (range < end - start) {
                    start = all[l].first;
                    end = all[i].first;
                }
                
                if (--m[all[l].second] == 0) {
                    ct--;
                }
                l++;
            }                     
        }
        return {start, end};
    }
};