class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> m;
        for (int n : nums) {
            sum += n;
            m[n]++;
        }
        int out = INT_MIN;
        for (int n: nums) {
            int rest_sum = sum - n;
            if (rest_sum % 2 == 0) {
                if (rest_sum / 2 == n) {
                    if (m[(sum - n)/2] > 1) {
                        out = max(out, n);
                    }
                } else {
                    if (m[(sum - n)/2] > 0) {
                        out = max(out, n);
                    }
                }

            }

        }
        return out;
    }
};