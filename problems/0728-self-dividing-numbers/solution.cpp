class Solution {
private:
    bool div(int x) {
        int c = x;
        while (x) {
            if (x % 10 == 0) {
                return false;
            }
            if (c % (x % 10) != 0) {
                return false;
            }
            x /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> out;
        for (int x = left; x <= right; x++) {
            if (div(x)) {
                out.push_back(x);
            } 
        }
        return out;
    }
};