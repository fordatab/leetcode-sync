class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2) {
        if (v1[1] == v2[1]) {
            return v1[0] > v2[0];
        }
        return v1[1] < v2[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        for (auto i : intervals) {
            cout << i[0] << " " << i[1] << endl;
        }
        unordered_set<int> nums;
        for (auto i : intervals) {
            int ct = 0;
            for (auto n : nums) {
                if (n >= i[0] and n <= i[1]) {
                    ct++;
                }

            }
            if (ct == 0) {
                nums.insert(i[1]);
                nums.insert(i[1] - 1);
            }
            if (ct == 1) {
                nums.insert(i[1]);
            }
        }
        return nums.size(); 
    }
};