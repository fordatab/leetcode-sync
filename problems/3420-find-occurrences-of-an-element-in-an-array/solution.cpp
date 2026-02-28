class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> out;
        vector<int> occurrs;
        for (int i = 0; i < nums.size(); i++) {
            if (x == nums[i]) {
                occurrs.push_back(i);
            }
        }
        for (int q : queries) {
            if (q > occurrs.size()) {
                out.push_back(-1);
            } else {
                out.push_back(occurrs[q-1]);
            }
        }
        return out;
    }
};