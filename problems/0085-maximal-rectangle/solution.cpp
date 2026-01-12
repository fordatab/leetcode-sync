class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int out = 0;
        stack<pair<int, int>> stk;
        stk.push({-1, 0});
        for (int x = 0; x < heights.size(); x++) {
            while (stk.top().first != -1 and stk.top().second > heights[x]) {
                int height = stk.top().second;
                stk.pop();
                int width = x - stk.top().first - 1;
                int area = height * width;
                out = max(out, area);
            }
            stk.push({x, heights[x]});
        } 
        while (stk.top().first != -1 ) {
            int height = stk.top().second;
            stk.pop();
            int width = heights.size() - stk.top().first - 1;
            int area = height * width;
            out = max(out, area);
        }
        return out;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int out = 0;
        for (int x = 0; x < matrix.size(); x++) {
            vector<int> heights(matrix[0].size());
            for (int z = 0; z < matrix[0].size(); z++) {
                for (int y = x; y >= 0; y--) {
                    if (matrix[y][z] == '1') {
                        heights[z]++;
                    } else {
                        break;
                    }
                }
            }
            out = max(out, largestRectangleArea(heights));
        }
        return out;
    }
};