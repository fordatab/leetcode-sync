class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> s;
        for (int x = 0; x < n; x++) {
            s.push_back({capital[x], profits[x]});
        }
        sort(begin(s), end(s));
        priority_queue<int> cap;
        int i = 0;
        while (k--) {
            while (i < n && s[i].first <= w) {
                cap.push(s[i].second);

                i++;
            }
            if (cap.empty()) {
                break;
            }

            w += cap.top();
            cap.pop();

        }
        return w;
    }
};