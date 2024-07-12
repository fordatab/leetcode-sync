class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int a : nums) {
             if (m[a] == 0) {
                m[a]++;
             } else {
                return a;
             }
        }
        return -1;
    }
};