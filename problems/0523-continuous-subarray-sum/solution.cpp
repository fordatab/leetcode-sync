class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
<<<<<<< HEAD
        vector<int> prefix(n);
        prefix[0] = nums[0];
        prefix[0] %= k;
        unordered_map<int, vector<int>> pre;
        pre[prefix[0]].push_back(0);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
            prefix[i] %= k;
            if (prefix[i] == 0) {
                return true;
            }
            pre[prefix[i]].push_back(i);
        }
        for (int i : prefix) {
            cout << i << " ";
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sum %= k;
            if (pre.count(sum)) {
                if (pre[sum].back() - (i + 1) > 0) {
                    return true;
                } 
            }
=======
        int prefix = 0;
        unordered_map<int, int> pre;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            prefix %= k;
            pre[prefix] = i;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (pre[sum] - i > 0) {
                return true;                 
            }
            sum += nums[i];
            sum %= k;
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
        }
        return false;
        
    }
};