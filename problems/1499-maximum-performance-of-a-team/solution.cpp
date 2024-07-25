class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {efficiency[i], speed[i]};
        }
        
        // Sort pairs based on nums2 in descending order
        sort(pairs.rbegin(), pairs.rend());
        
        // Use a min heap to keep track of k largest elements from nums1
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long result = 0;
        
        for (const auto& [a, b] : pairs) {            
            pq.push(b);
            sum += b;
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            result = max(result, sum * a);
        }
        
        return result % (1000000007);
    }
};