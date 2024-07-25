class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> g;
        for (auto a : triplets) {
            if (a[1] > target[1] || a[2] > target[2] || a[0] > target[0]) {
                continue;
            }
            for (int x = 0; x < 3; x++) {
                if (a[x] == target[x]) {
                    g.insert(x);
                }
            }
        }
        return g.size() == 3;
    }
};
