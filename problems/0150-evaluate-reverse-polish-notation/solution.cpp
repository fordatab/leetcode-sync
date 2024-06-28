class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string str : tokens) {
            if (str == "+" || str == "-" ||  str == "*" || str == "/") {
                int two = s.top();
                s.pop();
                int one = s.top();
                s.pop();
                switch(str[0]) {
                    case '+': s.push(one + two); break;
                    case '-': s.push(one - two); break;
                    case '*': s.push(one * two); break;
                    case '/': s.push(one / two); break;
                    default: break;
                }
            } else {
                s.push(stoi(str));
            }
        }
        return s.top();
    }
};
