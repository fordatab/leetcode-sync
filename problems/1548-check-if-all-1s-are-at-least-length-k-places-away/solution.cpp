class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -k -1;
        for (int x = 0; x < nums.size(); x++) {
            if (nums[x]) {
                cout << x << " " << prev << endl;
                if (x-prev-1<k) {
                    return false;
                } else {
                    prev = x;
                }
            }
        }
        return true;
    }
};