class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        tuple<int, int, int> t = {0, 0, 0};
        for (auto c : moves) {
            if (c == 'L') {
                get<0>(t)++;
            } else if (c == 'R') {
                get<1>(t)++;
            } else {
                get<2>(t)++;
            }
        }
        int n = get<0>(t) - get<1>(t);
        if (n < 0) {
            return abs(n) + get<2>(t);
        } else {
            return n + get<2>(t);
        }
    }
};