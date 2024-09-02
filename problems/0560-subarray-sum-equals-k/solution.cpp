class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int x = 1; x < n; x++) {
            prefix[x] = prefix[x-1] + nums[x];
        }
        unordered_map<int, int> m;
        int out = 0;
        for (int x = 0; x < n; x++) {
            if (prefix[x] == k) {
                out++;
            }
            if (m[prefix[x]-k] != 0) {
                out += m[prefix[x] - k];
            }
            m[prefix[x]]++;


        }
        return out;
        // 0, 1 = 0, 2, - 1, 2
        
    }
};