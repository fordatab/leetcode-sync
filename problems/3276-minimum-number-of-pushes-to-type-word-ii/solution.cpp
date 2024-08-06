class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> m;
        for (auto c : word) {
            m[c]++;
        }
        vector<int> arr;
        for (auto [a, b] : m) {
            arr.push_back(b);
        }
        sort(rbegin(arr), rend(arr));
        int out = 0;
        for (int x = 0; x < arr.size(); x++) {
            out += arr[x] * (x/8 + 1);
        }
        return out;
    }
};