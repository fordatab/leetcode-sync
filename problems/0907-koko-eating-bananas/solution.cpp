class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long l = 1;
        long r = *max_element(piles.begin(), piles.end());
        while (l <= r) {
            long hours = 0;
            int x = (r - l)/2 + l;
            for (auto y : piles) {
                hours += y/x;
                if (y % x) {
                    hours ++;
                }
            }
            if (hours > h) {
                l = x + 1;
            } else {
                r = x - 1;
            }
        }
        return r + 1;
    }
};
