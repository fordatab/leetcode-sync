class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groups(groupSizes.size()+1);
        for (int x = 0; x < groupSizes.size(); x++) {
            groups[groupSizes[x]].push_back(x);
        }
        // for (auto x : groups) {
        //     for (int a : x) {
        //         cout << a << " ";
        //     }
        //     cout << endl;
        // }
        vector<vector<int>> out;
        for (int a = 0; a < groups.size(); a++) {
            if (!groups[a].empty()) {
                vector<int> n;
                for (int x = 0; x < groups[a].size(); x++) {
                    if (x > 0 && x%a == 0) {
                        out.push_back(n);
                        n = {};
                    }
                    n.push_back(groups[a][x]);
                }
                out.push_back(n);
            }
        }
        return out;
    }
};