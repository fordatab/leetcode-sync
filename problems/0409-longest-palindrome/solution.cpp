class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> charCount(128);
        for (const char& c : s) {
            charCount[c]++;
        }
        
        int length = 0;
        bool hasOdd = false;
        
        for (int count : charCount) {
            if (count % 2) {
                length--;
                hasOdd = true;
            }
            length += count;

        }
        
        return length + hasOdd;
    }
};