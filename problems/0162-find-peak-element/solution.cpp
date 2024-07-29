class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums.size() == 1) {
            return 0;
        }
        if (nums.size() == 2) {
            return nums[0] > nums[1] ? 0 : 1;
        }
        while (l <= r) {
            int mid = (r - l)/2 + l;
            cout << mid << endl;
            if (mid == 0) {
                return nums[0] > nums[1] ? 0 : 1;
            }
            if (mid == nums.size() - 1) {
                return mid;
            }
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (nums[mid] > nums[mid - 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};