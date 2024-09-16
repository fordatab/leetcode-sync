class Solution {
public:
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
