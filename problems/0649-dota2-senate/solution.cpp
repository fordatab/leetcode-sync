class Solution {
public:
    string predictPartyVictory(string senate) {
        int r_ct = 0;
        int d_ct = 0;
        queue<char> q;
        for (char c : senate) {
            if (c == 'R') {
                r_ct++;
            } else {
                d_ct++;
            }
            q.push(c);
        }
        int to_pop_r = 0;
        int to_pop_d = 0;
        while (!q.empty()) {
            while (to_pop_r && q.front() == 'R') {
                r_ct--;
                q.pop();
                to_pop_r--;
            }
            while (to_pop_d && q.front() == 'D') {
                d_ct--;
                q.pop();
                to_pop_d--;
            }
            if (r_ct == 0) {
                return "Dire";
            }
            if (d_ct == 0) {
                return "Radiant";
            }
            if (q.front() == 'R') {
                q.pop();
                q.push('R');
                to_pop_d++;
            } else {
                q.pop();
                q.push('D');
                to_pop_r++;
            }
        }
        return "";
    }
};