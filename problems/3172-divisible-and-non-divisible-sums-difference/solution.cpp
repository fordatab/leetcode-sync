class Solution {
public:
    int differenceOfSums(int n, int m) {
        int t = n*(n+1)/2;
        int a = n/m;
        int j = (a * m * (1 + a)) / 2;
        return t -2*j;

    }
};