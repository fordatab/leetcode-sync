class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = 0;
        int j = 0;
        int out = 0;
        while (i < mat.size() && j < mat[0].size()) {
            out += mat[i][j];
            i++;
            j++;
        }
        i = 0;
        j = mat[0].size()-1;
        while (i < mat.size() && j > -1) {
            out += mat[i][j];
            i++;
            j--;
        }
        if (mat.size()%2) {
            out-= mat[mat.size()/2][mat.size()/2];
        }
        return out;
        
    }
};