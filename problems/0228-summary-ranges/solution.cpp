class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> out;
        string tmp;
        int i = 0;
        int x = 0;
        cout << nums.empty()  << " " << x << endl;
        if (nums.empty())        return {};

        for (x; x < nums.size()-1; x++) {
            i = x;
            while (x < nums.size()-1 && nums[x] + 1 == nums[x+1]) {
                x++;
            }
            if (i == x) {
                out.push_back(to_string(nums[x]));
            } else {
                cout << nums[x]<< endl;
                out.push_back(to_string(nums[i]) + "->" + to_string(nums[x]));
            }

        }
        if (x == nums.size()-1) {
            out.push_back(to_string(nums[x]));
        }
        cout << x << endl;
        return out;
    }
};