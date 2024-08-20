class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto idx = word.find(ch);
        if (idx != string::npos) {
            // Reverse the substring from the beginning to the found character
            reverse(word.begin(), word.begin() + idx + 1);
        }
        return word;
    }
};
