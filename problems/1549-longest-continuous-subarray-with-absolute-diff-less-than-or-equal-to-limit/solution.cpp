class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int l = 0;
        int out = 0;
        for (int r = 0; r < nums.size(); r++) {
            s.insert(nums[r]);
            cout << *s.rbegin() << " " <<  *s.begin() << endl; 
            // while (r + 1 < nums.size() and *s.rbegin() - *s.begin() <= limit) {
            //     r++;
            //     s.insert(nums[r]);
            // }
            
            while (l < r and *s.rbegin() - *s.begin() > limit) {
                auto it = s.find(nums[l]);
                s.erase(it);
                l++;
                
            }
            out = max(out, (int)s.size()); 
            
        }
        return out;
        
    }
};