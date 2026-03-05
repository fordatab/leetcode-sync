class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ct1 = __builtin_popcount(num1);
        int ct2 = __builtin_popcount(num2);
        cout << ct1 << " " << ct2 << endl;
        int candidate = num1;
        if (ct2 > ct1) {
            // cout << "add" << endl;
            int i = 0;
            while (i < 32 and ct2 > ct1) {
                if (((candidate >> i) & 1) == 0) {
                    candidate |= (1 << i);
                    ct2--;
                }
                i++;
            }
        } else {
            int i = 0;
            while (i < 32 and ct1 > ct2) {
                if (((candidate >> i) & 1) == 1) {
                    candidate &= (~(1 << i));
                    ct1--;
                }
                i++;
            }
        }
        return candidate;

    }
};