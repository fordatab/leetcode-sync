class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> f(nums1.begin(), nums1.end());
        unordered_set<int> s(nums2.begin(), nums2.end());
        vector<int> out;
        for (int x : f) {
            if (s.find(x) != s.end()) {
                out.push_back(x);
            }
        }
        return out;

    }
};