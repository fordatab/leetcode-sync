class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size());
        vector<int> forwards(nums.size()+2, 1);
        vector<int> backwards(nums.size()+2, 1);
        forwards[1] = nums[0];
        for (int x = 2; x < nums.size()+1; x++) {
            forwards[x] = nums[x-1] * forwards[x-1];
        }
        backwards[nums.size()] = nums[nums.size()-1];
        for (int x = nums.size() - 1; x >= 1; x--) {
            backwards[x] = nums[x-1] * backwards[x+1];
        }

        for (int x = 0; x < nums.size()+2; x++) {
            cout << forwards[x]<< " ";
        }
        cout << endl;
        for (int x = 0; x < nums.size()+2; x++) {
            cout << backwards[x]<< " ";
        }
        for (int x = 0; x < nums.size(); x++) {
            out[x] = backwards[x + 2] * forwards[x];
        }
        return out;
    }
};
