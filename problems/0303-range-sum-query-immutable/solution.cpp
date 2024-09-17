class NumArray {
private:
    vector<int> n; 
public:
    NumArray(vector<int>& nums) {
        n = nums;
    }
    
    int sumRange(int left, int right) {
        return accumulate(n.begin() + left, n.begin() + right + 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */