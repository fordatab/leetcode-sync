class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) {
            return nums2.size() % 2 ? nums2[nums2.size()/2] : (nums2[nums2.size()/2]+nums2[nums2.size()/2-1])/2.0;
        }
        if (nums2.size() == 0) {
            return nums1.size() % 2 ? nums1[nums1.size()/2] : (nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2.0;
        }
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        if (B.size() < A.size()) {
            swap(A, B);
        }
        int total = nums1.size() + nums2.size();
        int half = (total+1)/2;
        int l = 0;
        int r = nums1.size();
        while (l <= r) {
            int mid = (r - l)/2 + l;
            int mid_2 = half - mid;

            int a_l = (mid > 0) ? nums1[mid-1] : INT_MIN;
            int a_r = (mid < nums1.size()) ? nums1[mid] : INT_MAX;
            int b_l = (mid_2 > 0) ? nums2[mid_2-1] : INT_MIN;
            int b_r = (mid_2 < nums2.size()) ? nums2[mid_2] : INT_MAX;
            cout << a_l << " " << a_r << " " << b_l << " " << b_r << endl;
            if (a_l <= b_r && b_l <= a_r) {
                if (total % 2 != 0) { // odd
                    return max(a_l, b_l);
                } else {
                    return (max(a_l, b_l) + min(a_r, b_r))/2.0;
                }
            }
            if (a_l > b_r) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
