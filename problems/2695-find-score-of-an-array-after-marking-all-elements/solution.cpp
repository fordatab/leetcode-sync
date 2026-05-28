class Solution {
public:
    long long findScore(vector<int>& nums) {
<<<<<<< HEAD
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push({nums[i], i});
        }
        unordered_set<int> marked;
        long long out = 0;
        while (marked.size() < nums.size()) {
            auto [a, b] = q.top(); q.pop();
            if (marked.find(b) != marked.end()) {
                continue;
            }
            out += a;
            if (b > 0) {
                marked.insert(b - 1);
            }
            if (b < nums.size() - 1) {
                marked.insert(b + 1);
            }
            marked.insert(b);
        }
        return out;
=======
        long long ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            int currentStart = i;
            while (i + 1 < nums.size() && nums[i + 1] < nums[i]) {
                i++;
            }
            for (int currentIndex = i; currentIndex >= currentStart;
                 currentIndex -= 2) {
                ans += nums[currentIndex];
            }
        }
        return ans;
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
    }
};