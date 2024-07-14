class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for (int a : nums) {
            switch(a%3) {
                case 0: break;
                case 1: ops++; break;
                case 2: ops++; break;
            }
        }
        return ops;
    }
};