class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> m;
        int out = -1;
        for (int n : nums) {


            if (m[-n] != 0) {
                out = max(out, abs(n));
            }
            m[n]++;
            
        }
        return out;
    }
};