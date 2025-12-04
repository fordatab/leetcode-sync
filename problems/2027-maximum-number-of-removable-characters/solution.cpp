class Solution {
public:
    bool check(string& s, string& p, vector<int>& removable, int k) {
        // 1. Create a "map" of removed indices for O(1) lookup.
        // using vector<char> is often faster than vector<bool> in C++
        vector<char> isRemoved(s.size(), 0);
        
        for (int i = 0; i < k; i++) {
            isRemoved[removable[i]] = 1;
        }

        // 2. Standard Two-Pointer approach to check subsequence
        int i = 0; // Pointer for s
        int j = 0; // Pointer for p
        
        while (i < s.size() && j < p.size()) {
            // If this index is marked as removed, skip it entirely
            if (isRemoved[i] == 1) {
                i++;
                continue;
            }
            
            // If characters match, move the p pointer forward
            if (s[i] == p[j]) {
                j++;
            }
            
            // Always move the s pointer forward
            i++;
        }

        // If j reached the end of p, we successfully found the subsequence
        return j == p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0;
        int right = removable.size();
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If we can remove 'mid' characters and p is still a subsequence
            if (check(s, p, removable, mid)) {
                ans = mid;      // This k is valid, store it
                left = mid + 1; // Try to remove more (look to the right)
            } else {
                right = mid - 1; // We removed too many (look to the left)
            }
        }
        
        return ans;
    }
};