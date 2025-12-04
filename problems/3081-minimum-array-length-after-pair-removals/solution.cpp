class Solution {
public:
    bool check(int k, vector<int>& nums) {
        int i = 0;
        int j = nums.size() - k;
        for (; i < k; i++) {
            if (nums[i] >= nums[j+i]) {
                return false;
            }
        }
        return true;
    }

    int minLengthAfterRemovals(vector<int>& nums) {
        int l = 0;
        int r = nums.size() / 2;
        int k = 0;
        while (l <= r) {
            int mid = (r - l)/2 + l;
            // cout << mid << " " << check(mid, nums) << endl;
            if (check(mid, nums)) {
                k = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return nums.size() - 2 * k; 
    }
};