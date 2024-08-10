class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> pos = {0, 0};
        for (const char& c : moves) {
            switch (c) {
                case 'U' : pos.second++; break;
                case 'D' : pos.second--; break;
                case 'R' : pos.first++; break;
                case 'L' : pos.first--; break;
            }
        }
        return pos.first == 0 && pos.second == 0;
    }
};