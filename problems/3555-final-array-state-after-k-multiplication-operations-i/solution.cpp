class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int x = 0; x < nums.size(); x++) {
            pq.push({nums[x], x});
        }
        for (int x = 0; x < k; x++) {
            auto [a, b] = pq.top();
            a *= multiplier;
            pq.pop();
            pq.push({a, b}); 
        }
        while (!pq.empty()) {
            nums[pq.top().second] = pq.top().first;
            pq.pop();
        }
        return nums;

    }
};