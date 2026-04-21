class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string out;
        int i = 0;

        for (int space : spaces) {
            out += s.substr(i, space - i) + " ";
            i = space;
        }
        out += s.substr(i, s.size() - i);
        return out;
    }
};