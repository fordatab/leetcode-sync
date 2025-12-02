class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk;  // Use string instead of stack<char>
        
        for (char c : num) {
            // Remove larger digits while we can
            while (!stk.empty() && k > 0 && stk.back() > c) {
                stk.pop_back();
                k--;
            }
            stk.push_back(c);
        }
        
        // Remove remaining k digits from the end
        while (k > 0 && !stk.empty()) {
            stk.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int i = 0;
        while (i < stk.size() && stk[i] == '0') {
            i++;
        }
        
        string result = stk.substr(i);
        return result.empty() ? "0" : result;
    }
};