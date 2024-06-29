class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.emplace_back(0);
        int prod = 0;
        stack<pair<int, int>> stack;
        for (int x = 0; x < heights.size(); x++) {
            if (stack.empty() || stack.top().second <= heights[x]) {
                stack.push({x, heights[x]});
            } else {
                int count = 0;
                int index = x;
                while (!stack.empty() && heights[x] < stack.top().second) {
                    
                    count = (index - stack.top().first);
                    prod = max(prod, (index - stack.top().first) * stack.top().second);
                    // cout << stack.top().first << " " << stack.top().second << endl;
                    // cout << x << " " << count << " " << heights[x] << endl;

                    stack.pop();
                } 
                stack.push({index - count, heights[x]});
            }
            cout << prod << endl;
        }
        int index_max;
        if (!stack.empty()) {
            index_max = stack.top().first;
        }
        while (!stack.empty()) {
            prod = max(prod, (index_max - stack.top().first + 1) * stack.top().second);
            stack.pop();
        }
        return prod;
    }
};
