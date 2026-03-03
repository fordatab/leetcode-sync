class Solution {
public:
    int minFlips(string s) {
        int one_odd = 0;
        int one_even = 0;
        int zero_odd = 0;
        int zero_even = 0;
        int n = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    zero_even++;
                } else {
                    one_even++;
                }
            } else {
                if (s[i] == '0') {
                    zero_odd++;
                } else {
                    one_odd++;
                }
            }
        }
        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            int needed = min(zero_odd, zero_even) + min(one_odd, one_even);
            best = min(best, needed);
            char left = s[i];
            if (left == '0') {
                // remove from front
                zero_even--;
                // perform moving of indicies
                swap(zero_odd, zero_even);
                swap(one_odd, one_even);
                // add the end
                if (n % 2 == 0) {
                    zero_odd++;
                } else {
                    zero_even++;
                }
            } else {
                // remove from front
                one_even--;
                // perform moving of indicies
                swap(zero_odd, zero_even);
                swap(one_odd, one_even);
                // add the end
                if (n % 2 == 0) {
                    one_odd++;
                } else {
                    one_even++;
                }
            }
        }
        return best;
    }
};