class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        stack<int> stk;
        int out = 0;
        stk.push(0);
        for (int x : target) {
            int ct = 0;
            int t = 0;
            bool first = false; 
            while (!stk.empty() and stk.top() >= x) {
                if (!first) {
                    t = stk.top();
                    first = true;
                }
                // t = max(t, stk.top());
                stk.pop();
                // cout << ct << endl;

            }
            if (first) {
                ct += t - x;

            }

            stk.push(x);
            // cout << stk.top() << " " << ct << endl;
            out += ct; 
        }
        if (stk.top() != 0) {
            out += stk.top();
        }
        // while (!stk.empty() and stk.top() > 0) {
        //     stk.pop();
        //     out++;
        // }
        return out;
    }
};