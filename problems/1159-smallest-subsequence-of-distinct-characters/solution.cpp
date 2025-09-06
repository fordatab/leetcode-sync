class Solution {
public:
    std::string smallestSubsequence(std::string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        stack<char> stk;
        vector<bool> inStack(26, false);
        
        for (char c : s) {
            count[c - 'a']--;
            
            if (inStack[c - 'a']) {
                continue;
            }
            
            while (!stk.empty() && 
                   stk.top() > c && 
                   count[stk.top() - 'a'] > 0) {
                char removed = stk.top();
                stk.pop();
                inStack[removed - 'a'] = false;
            }
            
            stk.push(c);
            inStack[c - 'a'] = true;
        }
        
        string result;
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        
        return result;
    }
};