class Solution {
public:
    void bt(vector<int>& perm, vector<bool>& used, int n, int& ct) {
        if (perm.size() == n) {
            ct++;
            return;
        }
        int i = perm.size() + 1; // current position we are filling (1-indexed)
        for (int num = 1; num <= n; num++) {
            if (!used[num] && (num % i == 0 || i % num == 0)) {
                used[num] = true;
                perm.push_back(num);

                bt(perm, used, n, ct);

                // backtrack
                perm.pop_back();
                used[num] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> perm;
        vector<bool> used(n + 1, false);
        int ct = 0;
        bt(perm, used, n, ct);
        return ct;
    }
};