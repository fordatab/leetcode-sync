class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> l;
        vector<int> r;
        cout << nums.size() << endl;
        for (int x = 0; x < nums.size(); x++) {
            if (nums[x] < pivot) {
                l.push_back(nums[x]);
            } else if (nums[x] > pivot) {
                r.push_back(nums[x]);
            }
        }
        cout << l.size() <<  " " << r.size() << endl;
        int ls = l.size();
        for (int x = 0; x < nums.size() - ls - r.size(); x++) {
            l.push_back(pivot);
        }
        cout << l.size() << endl;
        for (int x = 0; x < r.size(); x++) {
            l.push_back(r[x]);
        }
        return l;
    }
};