class Solution {
private:
    long mk_pair(int a, int b) {
        return ((long)a << 32) | (unsigned int)b;
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        unordered_set<long> o;
        for (auto v : obstacles) {
            o.insert(mk_pair(v[0], v[1]));
        }
        int dir = 0;
        // 0 north
        // 1 east
        // 2 south
        // 3 west
        int x = 0;
        int y = 0;
        int out = 0;
        for (int c : commands) {
            if (c == -1) {
                dir = (dir + 1) % 4;

            } else if (c == -2) {
                dir = (dir - 1) % 4;
                if (dir == -1) {
                    dir = 3;
                }
            } else {
                while (c--) {
                    int n_x = x + (dir == 1) - (dir == 3);
                    int n_y = y + (dir == 0) - (dir == 2);
                    cout << n_x << " " << n_y << " " << dir << endl;

                    if (o.find(mk_pair(n_x, n_y)) != o.end()) {
                        cout << "fag " <<  mk_pair(n_x, n_y) << endl;
                        break;
                    }
                    x = n_x;
                    y = n_y;
                    out = max(out, x*x + y*y);
                }
            }
        }
        return out;
    }
};