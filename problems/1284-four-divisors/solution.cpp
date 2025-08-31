class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int out = 0;

        for (int a : nums) {
            int sum = 0;
            int ct = 0;

            for (int x = 1; x * x <= a; x++) {
                if (a % x == 0) {
                    int y = a / x;

                    if (x == y) {
                        sum += x;
                        ct++;
                    } else {
                        sum += x + y;
                        ct += 2;
                    }

                    if (ct > 4) break; // early stop
                }
            }

            if (ct == 4) out += sum;
        }

        return out;
    }
};
