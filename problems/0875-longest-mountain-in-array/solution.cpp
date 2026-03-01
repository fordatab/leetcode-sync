class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int out = 0;

        while (l < n) {
            int r = l;
            // go up mtn
            bool up = false;
            while (r + 1 < n and arr[r+1] > arr[r]) {
                r++;
            }
            if (l == r) {
                l++;
                continue;
            }
            bool down = false;
            // go down 
            while (r + 1 < n and arr[r+1] < arr[r]) {
                r++;
                down = true; 
            } 
            if (!down) {
                r++;
            }
            if (down) {
                out = max(out, r - l + 1);

            }
            l = r;
        }
        return out;

    }
};