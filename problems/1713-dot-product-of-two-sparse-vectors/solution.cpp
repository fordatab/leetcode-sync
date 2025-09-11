class SparseVector {
public:
    vector<pair<int, int>> vals;
    SparseVector(vector<int> &nums) {
        for (int x = 0; x < nums.size(); x++) {
            if (nums[x] != 0) {
                vals.push_back({x, nums[x]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int dot_sum = 0;
        int m = vec.vals.size();
        int n = vals.size();
        int t = 0;
        int o = 0;
        while (t < n and o < m) {
            if (vals[t].first == vec.vals[o].first) {
                dot_sum += vals[t].second * vec.vals[o].second;
                o++;
                t++; 
            } else if (vals[t].first > vec.vals[o].first) {
                o++;
            } else {
                t++;
            }
        }
        return dot_sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);