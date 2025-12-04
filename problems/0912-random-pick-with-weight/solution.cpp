class Solution {
public:
    vector<int> prefix;
    int m; 
    Solution(vector<int>& w) {
        for (int x : w) {
            if (prefix.empty()) {
                prefix.push_back(x);
            } else {
                prefix.push_back(prefix.back() + x);
            }
        }
        m = prefix.back();
    }
    
    int pickIndex() {
        return lower_bound(prefix.begin(), prefix.end(), rand() % m + 1) - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */