class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;
        int r = 0;
        deque<int> d;
        for (int x = 0; x < nums.size(); x++) {
            if (!d.empty() && d.front() == x - k) {
                d.pop_front();
            }
            if (d.size() == 0) {
                d.push_back(x);
            } else if (nums[d.back()] > nums[x]) {
                d.push_back(x);
            } else {
                while (!d.empty() && nums[d.back()] < nums[x]) {
                    d.pop_back();
                }
                d.push_back(x);
            }
            if (x + 1 >= k) { // window size achieved
                out.push_back(nums[d.front()]);
            }
        }
        return out;
    }
};
