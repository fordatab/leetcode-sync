class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, vector<vector<int>>> mp; 
        for(int i=0;i<arr.size()-1;i++) {
            mp[abs(arr[i]-arr[i+1])].push_back({arr[i],arr[i+1]});
        }
        return mp.begin()->second;
    }
};