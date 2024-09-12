class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;

        auto comp = [&nums1, &nums2](pair<int, int>& a, pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        pq.push({0, 0});
        
        while (k > 0 && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();

            
            result.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < nums2.size()) {
                pq.push({i, j + 1});
            }
            
            if (j == 0 && i + 1 < nums1.size()) {
                pq.push({i + 1, 0});
            }
            
            k--;
        }
        
        return result;
    }
};