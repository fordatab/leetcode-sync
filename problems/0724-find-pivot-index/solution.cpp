class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> postfix(nums);
        if (nums.size() == 1) {
            return 0;
        }

        for (int x = 1; x < nums.size(); x++) {
            nums[x] += nums[x-1];
        }
        for (int x = nums.size()-2; x > -1; x--) {
            postfix[x] += postfix[x+1];
        }

        for (int a = 0; a < nums.size(); a++) {
            cout << nums[a] << " " << postfix[a] << endl;
        }

        for (int x = 0; x < nums.size(); x++) {
            if (x == 0) {
                if (postfix[1] == 0) {
                    return x;
                }
            } else if (x == nums.size()-1) {
                if (nums[x-1] == 0) {
                    return x;
                }
            } else if (nums[x-1] == postfix[x+1]) {
                return x;
            }
        }
        return -1;
    }
};