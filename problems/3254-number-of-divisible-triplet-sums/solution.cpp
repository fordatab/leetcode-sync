class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        int out = 0;
        int n = nums.size(); 
        for (int j = 1; j < n - 1; j++) {
            int mid = nums[j]; 
            unordered_map<int, int> freq;
            for (int i = 0; i < j; i++) {
                freq[nums[i] % d]++;
            }
            for (int k = j + 1; k < n; k++) {
                int need = (d - (mid + nums[k]) % d) % d;
                out += freq[need];
            }

        }
        return out; 
    }
};