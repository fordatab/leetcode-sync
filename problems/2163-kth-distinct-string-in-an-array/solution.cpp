class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<int,string> map;
        unordered_map<string,int> m;
        for (string s : arr) {
            m[s]++;
        }
        for (int x = 0; x < arr.size(); x++) {
            if (m[arr[x]] == 1) {
                map.insert({x, arr[x]});
            }
            if (map.size() == k) {
                break;
            }
        }
        if (map.size() < k) {
            return "";
        }
        return rbegin(map)->second;
    }
};