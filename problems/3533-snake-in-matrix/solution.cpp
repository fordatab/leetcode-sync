class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0;
        int y = 0;
        for (auto s : commands) {
            if (s == "DOWN") {
                y++;
            }
            if (s == "UP") {
                y--;
            }
            if (s == "RIGHT") {
                x++;
            }
            if (s == "LEFT") {
                x--;
            }
        }
        return y *n + x;
    }
};