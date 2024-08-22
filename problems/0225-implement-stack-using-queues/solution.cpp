class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i=1; i<q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int out = q.front();
        q.pop();
        return out;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};