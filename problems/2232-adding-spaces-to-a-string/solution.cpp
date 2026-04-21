#include <sstream>

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        stringstream ss;
        int i = 0;
        
        for (int space : spaces) {
            ss << s.substr(i, space - i) << " ";
            i = space;
        }
        ss << s.substr(i);
        
        return ss.str();
    }
};