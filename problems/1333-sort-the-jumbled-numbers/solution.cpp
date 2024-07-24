class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> a(nums.size());
        vector<int> out;
        for (int x = 0; x < nums.size(); x++) {
            string str = to_string(nums[x]);
            for (char& c : str) {
                c = mapping[c-'0'] +'0';
            }
            a[x] = {stoi(str), x};
        }
        sort(begin(a), end(a));
        for (auto [i, j] : a) {
            out.push_back(nums[j]);
        }
        return out;
    }
};