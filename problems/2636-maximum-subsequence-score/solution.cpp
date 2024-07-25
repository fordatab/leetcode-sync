#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {nums2[i], nums1[i]};
        }
        
        // Sort pairs based on nums2 in descending order
        sort(pairs.rbegin(), pairs.rend());
        
        // Use a min heap to keep track of k largest elements from nums1
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long result = 0;
        
        for (const auto& pair : pairs) {
            int num2 = pair.first;
            int num1 = pair.second;
            
            pq.push(num1);
            sum += num1;
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                result = max(result, sum * num2);
            }
        }
        
        return result;
    }
};