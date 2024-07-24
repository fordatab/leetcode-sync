class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for (const string& op : operations) {
            if (op == "D") {
                s.push(s.top() * 2);
            } else if (op == "+") {
                int top = s.top();
                s.pop();
                int newTop = top + s.top();
                s.push(top);
                s.push(newTop);
            } else if (op == "C") {
                s.pop();
            } else {
                s.push(stoi(op));
            }
        }
        
        int sum = 0;
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};