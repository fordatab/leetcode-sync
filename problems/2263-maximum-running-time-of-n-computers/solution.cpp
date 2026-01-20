class Solution {
public:
    bool check(long long time, int n, vector<int>& batteries) {
        long long required = (long long) time * n;
        long long sum = 0;
        for (int b : batteries) {
            sum += min<long long>(time, b);
        }
        return sum >= required;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long best = 0;
        long long l = 0;
        long long r = accumulate(batteries.begin(), batteries.end(), 0LL);
        while (l <= r) {
            long long mid = l + (r - l)/2;
            if (check(mid, n, batteries)) {
                best = mid;
                l = mid + 1; 
            } else {
                r = mid - 1;
            }
        }
        return best;
    }
};