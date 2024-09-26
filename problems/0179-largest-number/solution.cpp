class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert integers to strings for easier manipulation
        vector<string> numStrs;
        for (int num : nums) {
            numStrs.push_back(to_string(num));
        }
        
        // Custom sort
        sort(numStrs.begin(), numStrs.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        
        // Concatenate the sorted strings
        string result;
        for (string& numStr : numStrs) {
            result += numStr;
        }
        
        // Edge case: if the result starts with '0', all numbers were zero
        return result[0] == '0' ? "0" : result;
    }
};