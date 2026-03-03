class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();


        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }
        for (int i : prefix) {
            // cout << i << " ";
        }
        cout << endl;
        vector<int> suffix(n);
        suffix[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffix[i] = nums[i] + suffix[i+1];
        }
                for (int i : suffix) {
            // cout << i << " ";
        }
        cout << endl;
        vector<int> out(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                out[i] = suffix[i] - (nums[i] * (n-i-1)) - nums[0];
            } else if (i == n-1) {
                out[i] = (nums[i] * i) - prefix[i]+ nums[n-1]; 
            } else {
                            out[i] = (nums[i] * i) - prefix[i-1] + suffix[i+1] - (nums[i] * (n-i-1));

            }
        }
        return out;

        
    }
};