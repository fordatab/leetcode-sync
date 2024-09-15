class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        int map[102] = {};
        for (auto& num : nums){
            map[num]++;
            if (map[num] == 2)
                ans.push_back(num);
        }
        return ans;
    }
};