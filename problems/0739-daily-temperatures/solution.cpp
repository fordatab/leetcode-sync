class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stack;
        vector<int> out(temperatures.size(), 0); 
        for (int x = 0; x < temperatures.size(); x++) {
            while (!stack.empty() && temperatures[x] > stack.top().first) {
                int index = stack.top().second;
                out[index] = x - index;
                stack.pop();

            }
            stack.push({temperatures[x], x});
        }



        return out;
    }
};