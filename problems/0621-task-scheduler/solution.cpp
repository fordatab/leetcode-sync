class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task(26);
        for (char t : tasks) {
            task[t-'A']++;
        }

        priority_queue<int> pq;
        for (int a : task) {
            if (a > 0) {
                pq.push(a);
            }
        }
        queue<pair<int, int>> q;
        int time = 0;
        while (!pq.empty() || !q.empty()) {
            // cout << pq.size() << " " << q.size() << endl;
            if (q.front().second == time) {
                // cout << "a" << endl;
                int v = q.front().first;
                q.pop();
                pq.push(v);
            }
            if (pq.size() == 0) {
                cout << "fag" << endl;
                time++;
            } else {
                int v = pq.top();
                // cout << v << endl;
                pq.pop();
                if (v != 1) {
                    q.push({v - 1, time + n + 1});
                }
                time++;
            }
        }
        return time;
    }
};