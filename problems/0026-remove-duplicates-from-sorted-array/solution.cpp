class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // if (nums.size() == 1) {
        //     return 1;
        // }
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            while (r < nums.size() -1 && nums[r] == nums[r+1]) {
                r++;
            }
            cout << l << " " << r << endl;
            nums[l] = nums[r];
            l++;
        }
        for (int x : nums) {
            cout << x << " ";
        }
        cout << l << endl;
        return l;
    }
};