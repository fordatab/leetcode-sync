class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int area = 0;
        while (l < r) {
            area = max(area, min(heights[l], heights[r]) * (r - l));
            if (heights[l] > heights[r]) {
                r--;
            } else  {
                l++;
            }

        }
        return area;
    }
};
