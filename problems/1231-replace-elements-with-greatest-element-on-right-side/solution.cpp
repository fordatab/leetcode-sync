class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int m = -1;
        for (int x = arr.size() - 1; x >= 0; x--) {
            int pre = arr[x];

            arr[x] = m;
            m = max(m, pre);
        }
        return arr;
    }
};