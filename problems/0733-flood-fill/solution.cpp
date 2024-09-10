class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int start = image[sr][sc]; 
                if (start == color) {
            return image;
        }
        dfs(image, sr, sc, m, n, color, start);
        return image;

    }

    void dfs(vector<vector<int>>& image, int i, int j, int m, int n, int color, int start) {
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || image[i][j] != start) {
            return;
        }
        image[i][j] = color;
        dfs(image, i + 1, j, m, n, color, start);
        dfs(image, i - 1, j, m, n, color, start);
        dfs(image, i, j + 1, m, n, color, start);
        dfs(image, i, j - 1, m, n, color, start);

    }
};