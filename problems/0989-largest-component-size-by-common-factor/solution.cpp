class Solution {
public:
    vector<int> parent;
    vector<int> size;
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b]; // merge sizes
    }

    vector<int> trial_division1(int n) {
        vector<int> factorization;
        for (int d = 2; d * d <= n; d++) {
            while (n % d == 0) {
                factorization.push_back(d);
                n /= d;
            }
        }
        if (n > 1)
            factorization.push_back(n);
        return factorization;
    }

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
        // map factors to list of nums
        unordered_map<int, unordered_map<int, int>> m;
        for (int x = 0; x < n; x++) {
            int num = nums[x];
            for (auto f : trial_division1(num)) {
                if (m.count(f)) {
                    unite(x, m[f].begin()->first);
                }
                m[f][x]++;

            }

        }
        int out = 0;
        for (int x = 0; x < n; x++) {
            out = max(out, size[find(x)]); 
        } 
        return out;
    }
};