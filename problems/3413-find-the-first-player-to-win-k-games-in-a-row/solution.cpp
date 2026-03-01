class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        if (k >= n) {
            return distance(skills.begin(), max_element(skills.begin(), skills.end()));        
        }
        vector<int> wins(n);
        queue<pair<int, int>> q;
        pair<int, int> cur = {skills[0], 0};
        for (int i = 1; i < n; i++) {
            q.push({skills[i], i});
        }

        while (true) {
            auto f = q.front(); q.pop();
            auto s = cur;
            if (f.first > s.first) {
                if (++wins[f.second] == k) {
                    return f.second;
                } 
                wins[s.second] = 0;
                cur = f;
                q.push(s);
            } else {
                if (++wins[s.second] == k) {
                    return s.second;
                }
                wins[f.second] = 0;
                q.push(f);
            }

        }
        return -1;
    }
};