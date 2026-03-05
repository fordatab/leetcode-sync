class Solution {
public:
    string smallestString(string s) {
        int n = (int)s.size();
        size_t i = s.find_first_not_of('a');

        if (i == string::npos) {
            // all 'a'
            s[n - 1] = 'z';
            return s;
        }

        // decrement until next 'a' or end
        for (size_t j = i; j < s.size() && s[j] != 'a'; j++) {
            s[j]--;
        }
        return s;
    }
};