class Solution {
public:
<<<<<<< HEAD
    void nextPermutation(vector<int>& array) {
        int i = array.size() - 1;
        
        // Find the longest non-increasing suffix
        while (i > 0 && array[i - 1] >= array[i])
            i--;
        
        // If we are at the last permutation, reverse the whole array
        if (i <= 0) {
            reverse(array.begin(), array.end());
            return;
        }

        // Find the rightmost element that exceeds the pivot (array[i - 1])
        int j = array.size() - 1;
        while (array[j] <= array[i - 1])
            j--;
        
        // Swap the pivot with array[j]
        swap(array[i - 1], array[j]);
        
        // Reverse the suffix starting at array[i]
        reverse(array.begin() + i, array.end());
    }
};
=======
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }

// private:
//     void swap(vector<int>& nums, int i, int j) {
//         int temp = nums[i];
//         nums[i] = nums[j];
//         nums[j] = temp;
//     }
};
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
