class Solution {
public:
    string toLowerCase(string& s) {
        for (char& c : s)
            if('A'<=c && c<='Z')
                c |= 0b00100000;
        return s;
    }
};