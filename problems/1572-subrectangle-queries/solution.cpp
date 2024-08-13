class SubrectangleQueries {
private:
    vector<vector<int>> r;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        swap(r, rectangle);
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int x = row1; x <= row2; x++) {
            for (int y = col1; y <= col2; y++) {
                r[x][y]= newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return r[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */