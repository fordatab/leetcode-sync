class Solution {
private:
    bool is_prime(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
    
        for (int i = 5; i <= sqrt(n); i = i + 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

public:
    int nonSpecialCount(int l, int r) {
        int c = 0;
        // for (int x = l; x <= r; x++) {
        //     if ()
        // }
        double lower = sqrt(l);
        double higher = sqrt(r);
        int lo = ceil(lower);
        int high = floor(higher);
        for (int x = lo; x <= high; x++) {
            if (is_prime(x)) {
                c++;
            }
        }
        cout << c << endl;
        return r - l + 1 - c;
    }
};