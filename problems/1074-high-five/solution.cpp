class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> scores;
        
        // Store top 5 scores for each student using min-heap
        for (auto& item : items) {
            int id = item[0], score = item[1];
            scores[id].push(score);
            if (scores[id].size() > 5) {
                scores[id].pop(); // Remove smallest if we have more than 5
            }
        }
        
        // Calculate averages
        vector<vector<int>> result;
        for (auto& [id, pq] : scores) {
            int sum = 0;
            while (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
            result.push_back({id, sum / 5});
        }
        
        // Sort by student ID
        sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        
        return result;
    }
};