class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> s(begin(stones), end(stones));
        while (s.size() > 1) {
            int f = s.top();
            s.pop();
            int g = s.top();
            s.pop();
            if (g < f) {
                s.push(f-g);
            }
        }
        return s.size() == 0 ? 0 : s.top();
    }
};
