class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> out;
        stack<int> stk;
        int i = 0;
        for (int x = 1; x < n + 1; x++) {
            if (target[i] == x) {
                out.push_back("Push");
                i++;
            } else {
                out.push_back("Push");
                out.push_back("Pop");
            }
            if (i == target.size()) {
                break;
            }
        }
        return out;
    }
};