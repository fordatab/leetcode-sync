class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (s.size() and nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if (s.size()) {
                left[i] = s.top();
            }
            s.push(i);
        }
        s = stack<int>();

        for (int i = n-1; i >= 0; i--) {
            while (s.size() and nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if (s.size()) {
                right[i] = s.top();
            }
            s.push(i);
        }
        for (int x = 0; x < n; x++) {
            int length = right[x] - left[x] -1 ;
            if ((long long)nums[x] * length > threshold) {
                return length;
            }
        }
        return -1;
    }
};