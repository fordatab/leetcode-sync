class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;
        vector<int> arr;
        dfs(out, arr, n, k, 1);
        return out;
    }

    void dfs(vector<vector<int>>& out, vector<int>& arr, int n, int k, int start) {
        if (arr.size() == k) {
            out.push_back(arr);
            return;
        }
        for (int x = start; x < n + 1; x++) {
            arr.push_back(x);
            dfs(out, arr, n, k, x + 1);
            arr.pop_back();
        }
    }
};