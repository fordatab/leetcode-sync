class Solution {
public:

    bool check(int capacity, int days, vector<int>& weights) {
        int cur = 0;
        int i = 0;
        int d = 0;
        while (d < days) {
            if (i == weights.size()) {
                return true;
            }
            if (cur + weights[i] <= capacity) {
                cur += weights[i];
                i++;
                
            } else {
                cur = weights[i];
                i++;
                d++;
            }
            // if (capacity == 2) cout << cur << " " << i << " " << d <<  endl;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = INT_MAX;
        int out = INT_MAX;

        while (l <= r) {
            int mid = (r - l)/ 2 + l;
            if (check(mid, days, weights)) {
                out = min(out, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return out;
    }
};