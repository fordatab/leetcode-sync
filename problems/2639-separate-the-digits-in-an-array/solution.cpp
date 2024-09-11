class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> out;
        for (int n : nums) {
            string t = to_string(n);
            for (auto & c : t) {
                out.push_back(c-'0');
            }
        }
        return out;
    }
};