class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (string a : operations) {
            if (a == "++X" || a == "X++") {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }
};