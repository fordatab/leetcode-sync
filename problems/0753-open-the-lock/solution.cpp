class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        int out = 0;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        q.push("0000");
        if (dead.find("0000") != dead.end()) {
            return -1;
        }
        dead.insert("0000");
        while (!q.empty()) {
            int level = q.size();

            while (level--) {
                string curr = q.front(); 
                q.pop();
                if (curr == target) {
                    return out;
                }
                for (int d = 0; d < 4; d++) {
                    string cpy = curr;
                    if (cpy[d] == '9') {
                        cpy[d] = '0';
                    } else {
                        cpy[d]++;
                    }

                    if (dead.find(cpy) == dead.end()) {
                        q.push(cpy);
                        dead.insert(cpy);
                    }
                    cpy = curr;
                    if (cpy[d] == '0') {
                        cpy[d] = '9';
                    } else {
                        cpy[d]--;
                    }
                    if (dead.find(cpy) == dead.end()) {
                        q.push(cpy);
                        dead.insert(cpy);
                    }
                } 
            }
            out++;
        }
        return -1;
    }
};