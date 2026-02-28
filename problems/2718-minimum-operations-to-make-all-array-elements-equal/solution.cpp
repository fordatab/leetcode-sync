class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> out;
        int n = nums.size();
        vector<long long> prefix(nums.size() + 1);
        long long total;

        prefix[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i+1] = nums[i] + prefix[i];
        } 
        for (int p : prefix) {
            cout << p << " ";
        }
        cout << endl;
        total = prefix.back();
        // cout << total << endl;
        for (int q : queries) {
            auto it = lower_bound(nums.begin(), nums.end(), q);
            int part1 = distance(nums.begin(), it);
            // if (it != nums.begin()) {
                part1--;
            //}
            int part2 = part1 + 1;
            cout << part1 << " " << part2 << endl;
            int val = 0;
            if (it != nums.end()) {
                val = *it;
            } 
            long long cost = (long long)(part1 + 1) * (long long) q - prefix[part1+1] + prefix[n] - prefix[part1+1] - (long long)(n - part2) * (long long)q;
            out.push_back(cost);
        }
        return out;
    }
};