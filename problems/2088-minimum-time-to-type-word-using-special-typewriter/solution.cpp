class Solution {
public:
    int minTimeToType(string word) {
        int out = 0;
        char prev = 'a';
        for (char c : word) {
            out++;
            int diff = abs(c - prev);
            out += min(diff, 26 - diff);
            prev = c;
            cout << diff << " " <<  out << endl;

        }   
        return out;
    }
};