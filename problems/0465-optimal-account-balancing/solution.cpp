class Solution {
public:
    void bt(int& out, vector<int>& debt, int cur, int idx) {
        if (idx == debt.size()) {
            out = min(out, cur);
            return;
        }
        if (debt[idx] == 0) {
            bt(out, debt, cur, idx + 1);
            return; 
        }
        for (int i = idx + 1; i < debt.size(); i++) {
            if (debt[i] * debt[idx] < 0) {
                debt[i] += debt[idx];
                bt(out, debt, 1 + cur, idx + 1);
                debt[i] -= debt[idx];
            }
        }

    }
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> debts;
        for (auto v : transactions) {
            debts[v[0]] -= v[2];
            debts[v[1]] += v[2];
        }
        vector<int> debt(13);
        for (auto [a, b] : debts) {
            if (b != 0) {
                debt[a] = b;
            }
        }
        int out = INT_MAX;
        bt(out, debt, 0, 0);
        return out;
    }
};