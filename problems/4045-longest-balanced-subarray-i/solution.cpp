class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int out = 0;
        for (int i = 0; i < nums.size(); i++) {
                unordered_map<int, int> even;
                unordered_map<int, int> odd;
                // cout << i << " " << j << endl;
                for (int k = i; k < nums.size(); k++) {
                    if (nums[k] % 2) {
                        odd[nums[k]]++;
                    } else {
                        even[nums[k]]++;
                    }
                                    // cout << even.size() << " " << odd.size() << endl;
                if (even.size() == odd.size()) {
                    out = max(out, k - i + 1);
                }
                }

            
        }
        return out;
    }
};