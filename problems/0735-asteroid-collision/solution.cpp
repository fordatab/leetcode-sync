class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int a : asteroids) {
            cout << a << endl;
            bool to_push = true;
            while (!s.empty() && a < 0 && s.top() > 0) {
                if (-1 * a == s.top()) {
                    s.pop();
                    to_push = false;
                    break;
                }
                if (-1 * a < s.top()) {
                    to_push = false;
                    break;
                }
                s.pop();
            }
            if (to_push) {
                s.push(a);
            }
        }
        vector<int> out;
        while (!s.empty()) {
            out.push_back(s.top());
            s.pop();
        }
        reverse(begin(out), end(out));
        return out;
    }
};