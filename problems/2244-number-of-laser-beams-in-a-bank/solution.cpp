class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int out = 0;
        vector<int> o;
        for (int x = 0; x < bank.size(); x++) {
            int g = 0;
            for (char c : bank[x]) {
                if (c == '1') {
                    g++;
                }
            }
            if (g) {
                o.push_back(g);
            }
        }
        if (o.empty()) {
            return 0;
        }
        for (int x = 0; x < o.size() -1 ; x++) {
            out += (o[x]*o[x+1]);
        }
        return out;
    }
};