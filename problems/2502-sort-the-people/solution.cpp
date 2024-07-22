class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> p(names.size());
        for (int x = 0; x < names.size(); x++) {
            p[x] = {heights[x], names[x]};
        }
        sort(begin(p), end(p));

        vector<string> out;
        for (auto [h, n] : p) {
            cout << h << '\n';
            out.push_back(n);
        }
        reverse(begin(out), end(out));
        return out;
    }
};