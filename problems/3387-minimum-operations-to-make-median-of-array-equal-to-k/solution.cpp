class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long out = 0;
        int n = nums.size();
        int median = n/2; 
        cout << nums[median] << endl;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (i < median) {
                cout << num - k << endl;
                out += max(num - k, 0);
            } else if (i > median) {
                out += max(k - num, 0);
                cout << k - num << endl;  
            } else {
                out += abs(k - num);    

            }
        }
        return out; 
    }
};