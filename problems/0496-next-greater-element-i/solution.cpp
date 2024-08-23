class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        for (int n : nums2) {
            while (!s.empty() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        for (int& x : nums1) {
            if (m.count(x)) {
                x = m[x];
            } else {
                x = -1;
            }
        }
        return nums1;
    }
};