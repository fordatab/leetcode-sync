class Solution {
public:
    string clearDigits(string s) {
        string out;
        for (char c : s) {
            if (!out.empty() && c <= '9') {
                out.pop_back();
            } else {
                out.push_back(c);
            }
        }
        return out;
    }
};