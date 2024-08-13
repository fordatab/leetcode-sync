class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1) {
            if (s.find(n) != s.end()) {
                return false;
            }
            s.insert(n);
            int s = 0;
            cout << s << endl;
            while (n) {
                s += (n%10)*(n%10);
                n /= 10;
            }
            n = s;
        }
        return true;
    }
};