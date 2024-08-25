class Solution {
public:
    double myPow(double x, int n) {
        if (!x) return 0;
        if (!n) return 1;
        double res = dnc(x, abs(static_cast<long>(n)));
        return (n >= 0) ? res : 1 / res;

    }
private:
    double dnc(double x, long n) {
        if (!n) return 1;
        double half = dnc(x, n/2);
        return n%2 ? half*half*x : half*half;
    }
};
