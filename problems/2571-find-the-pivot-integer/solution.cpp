class Solution {
public:
    int pivotInteger(int n) {
        int x = n*n + n;
        cout << x << endl;
        x /= 2;
        int s = sqrt(x);
        cout << s << endl;
        if ((s*s) == x) {
            return s;
        } else {
            return -1;
        }
    }
};