class Solution {
public:
    long long sideSum(long long peak, long long len) {
        if (len <= 0) return 0;
        if (peak >= len) {
            return (peak + (peak - len + 1)) * len / 2;
        } else {
            return peak * (peak + 1) / 2 + (len - peak);
        }
    }

    bool check(long long x, int n, int index, long long maxSum) {
        long long leftLen = index;
        long long rightLen = n - index - 1;
        long long sum = x + sideSum(x - 1, leftLen) + sideSum(x - 1, rightLen);
        return sum <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        long long l = 1, r = maxSum, best = 1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (check(mid, n, index, maxSum)) {
                best = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return (int)best;
    }
};