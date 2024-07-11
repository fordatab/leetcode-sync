class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> out;
        for (int a : nums) {
            out.push_back(a);
        }
        for (int a : nums) {
            out.push_back(a);
        }
        return out;
    }
};