class Solution {// Using Map & without sort
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        vector<int>ans;
        for(int i : nums1){
            freq[i]++;
        }
        for(int i : nums2){
            if (freq[i] > 0){
                freq[i]--; 
                ans.push_back(i);
            }
        }
        return ans;
    }
};