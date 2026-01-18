class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> small;
        multiset<int> large;
        vector<double> out;
        for (int x = 0; x < nums.size(); x++) {
            small.insert(nums[x]);
            large.insert(*small.rbegin());
            small.erase(prev(small.end()));
            if (small.size() < large.size()) {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
            if (small.size() + large.size() > k) {
                int idx = x - k;
                if (*small.rbegin() >= nums[idx]) {
                    auto it = small.find(nums[idx]);
                    small.erase(it);
                } else {
                    auto it = large.find(nums[idx]);
                    large.erase(it);
                }
                            if (small.size() > large.size() + 1) {
                large.insert(*small.rbegin());
                small.erase(prev(small.end()));
            } else if (large.size() > small.size()) {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
            }
            if (small.size() + large.size() == k) {
                out.push_back(small.size() > large.size() ? *small.rbegin() : ((double) *small.rbegin() + *large.begin()) * 0.5);
            }
        }
        return out;
    }
};