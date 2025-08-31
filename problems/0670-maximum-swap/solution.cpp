class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        int n = num;
        while (n) {
            digits.push_back(n%10);
            n/=10;
        }
        reverse(digits.begin(), digits.end());
        int i = 0;
        int top = 10;
        while (i < digits.size() and digits[i] <= top) {
            top = digits[i];
            i++;
        }
        // cout << i << endl;
        int m = 0;
        int idx = -1;
        for (int x = i; x < digits.size(); x++) {
                //             while (x + 1 < digits.size() and digits[x] == digits[x+1]) {
                //     x++;
                // }
            if (digits[x] >= m) {
                m = digits[x];
                idx = x;
            }
        } 
        if (idx != -1) {
            for (int x = 0; x < digits.size(); x++) {
                // while (x + 1 < digits.size() and digits[x] == digits[x+1]) {
                //     x++;
                // }
                if (digits[x] < m) {
                    swap(digits[x], digits[idx]);
                    break;
                }
            }
        }
        // cout << idx;
        int out = 0;
        int digit = 1;
                reverse(digits.begin(), digits.end());
        for (int x = 0; x < digits.size(); x++) {
            out += digit*digits[x];
            digit*= 10; 
        }
        return out;
        
    }
};