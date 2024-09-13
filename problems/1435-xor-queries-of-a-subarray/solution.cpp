class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // vector<int> prefix(arr.size());
        for (int x = 1; x < arr.size(); x++ ) {
            arr[x] ^= arr[x-1];
        }
        vector<int> out;
        for (auto q : queries ) {
            if (q[0] == 0) {
                out.push_back(arr[q[1]]);
            } else {
                out.push_back(arr[q[0]-1] ^ arr[q[1]]);
            }
        }
        return out;
    }
};