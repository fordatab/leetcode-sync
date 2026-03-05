class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> stk;

        vector<int> out(n);
        int curr = 0;
        for (string& l : logs) {
            replace(l.begin(), l.end(), ':', ' ');
            stringstream ss(l);
            int id;
            string start;
            int time;
            ss >> id;
            ss >> start;
            ss >> time;   
            if (stk.size()) {
                auto [t, i] = stk.top();
                out[i] += time - t;
                cout << i << " " << time - t + 1 << endl;
                if (start == "end") {
                    out[i]++;
                    stk.pop();
                    if (stk.size()) {
                        stk.top().first = time + 1;
                    }
                    continue;
                } else {
                    stk.top().first = time + 1;
                }
            }
            stk.push({time, id});
            
        }
        return out;
    }
};