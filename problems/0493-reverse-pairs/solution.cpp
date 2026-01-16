class Solution {
public:
    long long cnt = 0;

    void mergeCount(vector<int>& a, int l, int r) {
        if (r - l <= 1) return;
        int m = l + (r - l) / 2;
        mergeCount(a, l, m);
        mergeCount(a, m, r);

        // count cross pairs
        int j = m;
        for (int i = l; i < m; i++) {
            while (j < r && (long long)a[i] > 2LL * (long long)a[j]) j++;
            cnt += (j - m);
        }

        // merge sorted halves
        vector<int> tmp;
        tmp.reserve(r - l);
        int i = l; j = m;
        while (i < m && j < r) {
            if (a[i] <= a[j]) tmp.push_back(a[i++]);
            else tmp.push_back(a[j++]);
        }
        while (i < m) tmp.push_back(a[i++]);
        while (j < r) tmp.push_back(a[j++]);

        for (int k = 0; k < (int)tmp.size(); k++) a[l + k] = tmp[k];
    }

    int reversePairs(vector<int>& nums) {
        cnt = 0;
        mergeCount(nums, 0, (int)nums.size());
        return (int)cnt;
    }
};
