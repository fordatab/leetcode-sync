class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total = 0;
        int i = 0;
        for (int n : nums) {
            if (n %6 == 0) {
                total += n;
                i++;
            }

        }
        if (total == 0) {
            return total;
        }
        return total / i;
    }
};