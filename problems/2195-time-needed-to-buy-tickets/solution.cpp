class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        for (int x = 0; x < tickets.size(); x++) {
            q.push({tickets[x], x});
        }
        int t = 0;
        cout << q.front().second << endl;
        while (q.front().first != 1 || q.front().second != k) {
            if (q.front().first != 1) {
                q.push({q.front().first - 1, q.front().second});
            }
            q.pop();
            t++;
        }
        return t + 1;
    }
};