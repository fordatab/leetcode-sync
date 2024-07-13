class Solution {
public:
    bool isvowel(char c) {
    // Convert character to lowercase to simplify comparison
    c = tolower(c);
    // Check if the character is a vowel
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string reverseVowels(string s) {
        cout << s.size() << endl;
        int l = 0;
        int r = s.size() - 1;
        while (l <= r) {
            while (l < s.size() && !isvowel(s[l])) {
                l++;
            }
            while (r > -1 && !isvowel(s[r])) {
                r--;
            }
            if (l >= r) {
                break;
            }
            cout << s[l] << " " << s[r] << endl;
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
        return s;
    }
};