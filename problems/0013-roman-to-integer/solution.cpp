class Solution {
private:
    const unordered_map<char, int> vals = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
public:
    int romanToInt(string s) {
        reverse(begin(s), end(s));
        int biggest = 1;
        int out= 0;
        for (char c : s) {
            if (vals.at(c) > biggest) {
                biggest = vals.at(c);
            } 
            if (vals.at(c) < biggest) {
                out -= vals.at(c);
            } else {
                out += vals.at(c);
            }           
        }
        return out;
    }
};