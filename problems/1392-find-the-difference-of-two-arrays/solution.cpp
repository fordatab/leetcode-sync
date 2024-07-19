class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        for (int a : nums1) {
            s1.insert(a);
        }
        for (int b : nums2) {
            s2.insert(b);
        }
        vector<vector<int>> out(2);
        for (int a : s1) {
            if (s2.find(a) == end(s2)) {
                out[0].push_back(a);
            }
        }
        for (int b : s2) {
            if (s1.find(b) == end(s1)) {
                out[1].push_back(b);
            }
        }
        return out;
    }
};