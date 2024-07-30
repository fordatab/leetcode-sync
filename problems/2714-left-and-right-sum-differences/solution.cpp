class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        if (nums.size() == 1) {
            return {0};
        }
        vector<int> l(nums.size());
        vector<int> r(nums.size());
        l[0] = nums[0];
        r[nums.size() - 1] = nums[nums.size() -1];
        for (int x = 1; x < nums.size(); x++) {
            l[x] = l[x-1] + nums[x];
            r[nums.size() - x - 1] = r[nums.size() - x] + nums[nums.size() - x - 1];
            cout << l[x] << " " <<  r[nums.size() -x - 1] << endl;
        }
        vector<int> out;
        out.push_back(abs(r[1]));
        for (int x = 1; x < nums.size() - 1; x++) {
            out.push_back(abs(l[x-1]-r[x+1]));
        }
        out.push_back(abs(l[nums.size()-2]));
        return out;
    }
};