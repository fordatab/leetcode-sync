class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int out = 0;
        int prefix = 0;
        for (int num : nums) {
            prefix += num;
            int remainder = prefix % k;
            if (remainder < 0) {
                remainder += k;
            }
            out += m[remainder];
            m[remainder]++; 
        }
        return out;
    }
};