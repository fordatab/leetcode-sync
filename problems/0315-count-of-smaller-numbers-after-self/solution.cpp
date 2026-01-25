class Solution {
public:
    vector<int> ans;

    void mergeSort(vector<pair<int,int>>& a, int l, int r) {
        if (r - l <= 1) return;
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m, r);

        vector<pair<int,int>> tmp;
        int i = l, j = m, count = 0;

        while (i < m && j < r) {
            if (a[i].first <= a[j].first) {
                ans[a[i].second] += count;
                tmp.push_back(a[i++]);
            } else {
                count++;
                tmp.push_back(a[j++]);
            }
        }

        while (i < m) {
            ans[a[i].second] += count;
            tmp.push_back(a[i++]);
        }
        while (j < r) tmp.push_back(a[j++]);

        copy(tmp.begin(), tmp.end(), a.begin() + l);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);

        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        mergeSort(a, 0, n);
        return ans;
    }
};