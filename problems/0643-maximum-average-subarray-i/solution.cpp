class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0;
        long total = 0;
        long m = INT_MIN;
        for (int r = 0; r < nums.size(); r++) {
            total += nums[r];
            if (r - l + 1 == k) {
                cout << total << endl;
                m = max(total, m);
                total -= nums[l];
                l++;
            }
        }
        cout << m << endl;
        return static_cast<double>(m)/k;
    }
};