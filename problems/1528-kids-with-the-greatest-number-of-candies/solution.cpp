class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = *max_element(candies.begin(), candies.end());
        vector<bool> out;
        for (int a : candies) {
            out.push_back(a + extraCandies >= m);
        }
        return out;
    }
};