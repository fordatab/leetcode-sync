class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int,int>> st; // {functionId, lastTimestamp}

        for (const string& log : logs) {
            size_t p1 = log.find(':');
            size_t p2 = log.find(':', p1 + 1);

            int id = stoi(log.substr(0, p1));
            string type = log.substr(p1 + 1, p2 - p1 - 1);
            int time = stoi(log.substr(p2 + 1));

            if (type == "start") {
                if (!st.empty()) {
                    res[st.top().first] += time - st.top().second;
                }
                st.push({id, time});
            } else { // "end"
                res[st.top().first] += time - st.top().second + 1;
                st.pop();
                if (!st.empty()) {
                    st.top().second = time + 1;
                }
            }
        }
        return res;
    }
};