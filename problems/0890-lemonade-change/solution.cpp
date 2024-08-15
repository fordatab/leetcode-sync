class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0;
        int t = 0;
        for (auto a : bills) {
            if (a == 5) {
                f++;
            } else if (a == 10) {
                if (f-- < 1) {
                    return false;
                }
                t++;
            } else {
                if (t < 1) {
                    if (f < 3) {
                        return false;
                    }
                    f-=3;
                } else {
                    if (f < 1) {
                        return false;
                    }
                    t--;
                    f--;
                }
                
            }
                        cout << f << " " << t << " " << endl;

        }
        return true;
    }
};