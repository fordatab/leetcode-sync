#include <vector>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        // 1st pass
        int count1 = 0;
        int count2 = 0;

        // In C++, we don't need 'null', we can just use normal integers.
        // We initialize them to different values to avoid any initial overlap.
        int candidate1 = 0;
        int candidate2 = 1; 

        for (int n : nums) {
            if (candidate1 == n) {
                count1++;
            } else if (candidate2 == n) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = n;
                count1++;
            } else if (count2 == 0) {
                candidate2 = n;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        // 2nd pass
        std::vector<int> result;

        count1 = 0;
        count2 = 0;

        for (int n : nums) {
            if (n == candidate1) count1++;
            else if (n == candidate2) count2++;
        }

        int n = nums.size();
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);

        return result;
    }
};