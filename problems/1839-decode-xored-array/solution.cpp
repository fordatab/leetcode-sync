class Solution {
public:
    vector<int> decode(vector<int>& A, int cur) {
        vector<int> res = {cur};
        for (int& a: A)
            res.push_back(res.back()^a);
        return res;
    }
};