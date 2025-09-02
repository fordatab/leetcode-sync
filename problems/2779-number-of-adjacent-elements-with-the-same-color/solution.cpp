class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> out(queries.size());
        vector<int> arr(n);
        int count = 0;
        int i = 0;
        for (auto v : queries) {
            int idx = v[0];
            int col = v[1];
            int curr = arr[idx];
            int diff = 0;
            if (curr != 0) {
                if (idx > 0) {
                    if (curr == arr[idx - 1]) {
                        diff++;
                    }
                }
                if (idx < n - 1) {
                    if (curr == arr[idx + 1]) {
                        diff++;
                    }
                }
                count -= diff;
                diff = 0;
            }

            if (idx > 0) {
                if (col == arr[idx - 1]) {
                    diff++;
                }
            }
            if (idx < n - 1) {
                if (col == arr[idx + 1]) {
                    diff++;
                }
            }
            count += diff;
            out[i] = count;
            arr[idx] = col; 
            i++;
        }
        return out;
    }
};