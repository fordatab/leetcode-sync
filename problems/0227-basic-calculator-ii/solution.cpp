class Solution {
public:
    int calculate(string str) {
        stack<int> s;
        s.push(0);
        int prev_op = 0;
        for (char c : str) {
            if (c == ' ') {
                continue;
            }
            if (isdigit(c)) {

                s.top() = s.top() * 10 + (c -'0');
            } else {
                if (prev_op == -4) {
                    s.top() = -s.top(); 
                }
                if (prev_op == -1) {
                    int f = s.top();
                    s.pop();
                    s.pop();
                    s.top() = s.top() * f;
                }
                if (prev_op == -2) {
                    int f = s.top();
                    s.pop();
                    s.pop();
                    s.top() = s.top() / f;
                }
                if (c == '*') {
                    prev_op = -1;
                    s.push(-1);
                }
                if (c == '/') {
                    prev_op = -2;
                    s.push(-2);
                }
                if (c == '+') {
                    prev_op = -3;
                    s.push(-3);
                }
                if (c == '-') {
                    s.top() = s.top(); 
                    prev_op = -4;
                    s.push(-4);
                }
                s.push(0);
            }
        }
        if (prev_op == -1) {
            int x = s.top();
            s.pop();
            s.pop();
            s.top() *= x;
        }
        if (prev_op == -2) {
            int x = s.top();
            s.pop();
            s.pop();
            s.top() /= x;
        }
                if (prev_op    == -4) {
            s.top() = -s.top(); 
        }
        // stack<int> tmp ;
        // while (!s.empty()) {
        //     if (s.top() > 0) {
        //         s.top() = -s.top(); 
        //     }
        //     tmp.push(s.top());
        //     s.pop(); 
            

        // }
        // s = tmp;

        while (s.size() != 1) {
            int x = s.top();
            s.pop();
            int op = s.top();
            s.pop();
            // cout << s.top() << " " << x << " " << op << endl;
            // if (op == -1) {
            //     s.top() *= x;
            // }
            // if (op == -2) {
            //     s.top() = s.top() / x;
            //     // cout << s.top() << endl;
            //     // cout << s.size() << endl;
            // }
            // if (op == -3 ) {
                s.top() += x;
            // }
            // } if (op == -4) {
            //     s.top() -= x; 
            // }

        }
        return s.top();
    }
};