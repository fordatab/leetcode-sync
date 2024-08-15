class Solution {
public:
    int minimumSum(int num) {
        vector<int> arr(4);
        for (int x = 0; x < 4; x++) {
            arr[x] = num%10;
            num/=10;
        }
        sort(begin(arr), end(arr));
        return 10* arr[0] + 10*arr[1] + arr[2] + arr[3];

    }
};