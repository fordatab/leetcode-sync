class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds = 0;
        for (int x = 0; x < arr.size(); x++) {
            if (arr[x]%2) {
                odds++;
            } else {
                odds = 0;
            }
            if (odds == 3) {
                return true;
            }
        }
        return false;
    }
};