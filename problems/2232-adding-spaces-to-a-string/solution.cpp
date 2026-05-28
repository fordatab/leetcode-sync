<<<<<<< HEAD
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
=======
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
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
    }
};