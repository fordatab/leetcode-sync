class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int c = 0;
        for (int a : nums) {
            m[a]++;
            // cout << m[a] << endl;
        }

        for (int a : nums) {
            int target = k - a;
            if (m[a] == 0) {
                continue;
            }
            m[a]--;
            if (m[target] > 0) {
                c++;
                m[target]--;
            } else {
                m[a]++;
            }
        }
        return c;
    }
};