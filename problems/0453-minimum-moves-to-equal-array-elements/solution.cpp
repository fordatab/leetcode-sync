class Solution {
public:
    bool check(vector<int>& vec) {
        const int first_val = vec[0];
        return all_of(vec.begin(), vec.end(), [&](int val) {
            return val == first_val;
        });
    }
    int minMoves(vector<int>& nums) {
        int m = *min_element(nums.begin(), nums.end());
        int out = 0;
        for (int n : nums) {
            out += (n - m);
        }  
        return out; 
    }
};