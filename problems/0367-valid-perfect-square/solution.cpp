class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = 46340;
        while (l <= r) {
            int mid = (r - l)/2 + l;
            // cout << mid << endl;
            if (mid * mid == num) {
                return true;
            }
            if (mid * mid < num) {
                l = mid + 1;
            }
            if (mid * mid > num) {
                r = mid - 1;
            }
        }
        return false;
    }
};