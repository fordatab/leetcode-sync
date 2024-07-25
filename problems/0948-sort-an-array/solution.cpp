class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq(begin(nums), end(nums));
        for (int x = 0; x < nums.size(); x++) {
            nums[x] = pq.top();
            pq.pop();
        }
        return nums;
    }
};