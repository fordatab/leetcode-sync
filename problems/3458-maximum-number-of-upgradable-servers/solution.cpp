class Solution {
public:
bool valid(int ct, int up, int sl, int mny, int toUp) {
    // can't upgrade more than we own (optional sanity check)
    if (toUp > ct) return false;

    // how many we can sell
    long long sellCnt = max(0, ct - toUp);

    // compute total money in 64-bit
    long long totalMoney = (long long)mny + sellCnt * (long long)sl;

    // cost of upgrading `toUp` items
    long long cost = (long long)up * (long long)toUp;

    return cost <= totalMoney;
}

    int upgraded(int ct, int up, int sl, int mny) {
        int l = 0;
        int r = ct;
        int i = 0;
        while (l <= r) {
            int mid = (r - l)/2 + l;
            // cout << mid << " " << r << " " << l << " " << endl;
            if (valid(ct, up, sl, mny, mid)) {
                i = max(i, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return i;
    }
    vector<int> maxUpgrades(vector<int>& count, vector<int>& upgrade, vector<int>& sell, vector<int>& money) {
        vector<int> out(count.size());
        for (int x = 0; x < count.size(); x++) {
            out[x] = upgraded(count[x], upgrade[x], sell[x], money[x]);
        }
        return out;
    }
};