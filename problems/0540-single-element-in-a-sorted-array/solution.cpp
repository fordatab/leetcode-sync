class Solution {
public:
    int check(int idx, vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0; // Edge case: array size 1

        // Handle boundaries specifically to avoid out-of-bounds errors
        if (idx == 0) {
            return (nums[idx] == nums[idx + 1]) ? 2 : 0;
        }
        if (idx == n - 1) {
            return (nums[idx] == nums[idx - 1]) ? 3 : 0;
        }

        if (nums[idx] == nums[idx + 1]) return 2;
        if (nums[idx] == nums[idx - 1]) return 3;
        
        return 0; // Matches neither, this is the one!
    }
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (r - l)/2 + l;
            int s = check(mid, nums);
            if (s == 0) {
                return nums[mid];
            }
              if (s == 2) { // Matches Right: Pair is [mid, mid+1]
                if (mid % 2 == 0) {
                    // Pair starts at Even (Normal). Target is Right.
                    l = mid + 1; // You can also do mid + 2
                } else {
                    // Pair starts at Odd (Broken). Target is Left.
                    r = mid - 1;
                }
            } 
            else if (s == 3) { // Matches Left: Pair is [mid-1, mid]
                if (mid % 2 == 1) {
                    // Pair started at Even (mid-1). Normal. Target is Right.
                    l = mid + 1;
                } else {
                    // Pair started at Odd (mid-1). Broken. Target is Left.
                    r = mid - 1; // You can also do mid - 2
                }
            }
            cout << l << " " << r << " " << mid << " " <<s << endl;
        } 
        return nums[l];
    }
};