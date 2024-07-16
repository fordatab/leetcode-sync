class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c = 0;
        int r = 0;
        int l = 0;
        while (r < nums.size()) {
            if (val == nums[r]) {
                c++;
                
            } else {
                nums[l] = nums[r];
                cout << l << " " << r << endl;
                l++;
            }
            r++;
        }
        return nums.size()-c;
    }
};