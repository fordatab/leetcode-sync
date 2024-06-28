class MinStack {
private:
    vector<pair<int, int>> stack;  // Pair of (value, current minimum)

public:
    MinStack() {}
    
    void push(int val) {
        if (stack.empty()) {
            stack.push_back({val, val});
        } else {
            int current_min = min(val, stack.back().second);
            stack.push_back({val, current_min});
        }
    }
    
    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
        }
    }
    
    int top() {
        if (!stack.empty()) {
            return stack.back().first;
        }
        throw runtime_error("Stack is empty");
    }
    
    int getMin() {
        if (!stack.empty()) {
            return stack.back().second;
        }
        throw runtime_error("Stack is empty");
    }
};