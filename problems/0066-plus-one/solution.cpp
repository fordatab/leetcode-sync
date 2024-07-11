class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int i = digits.size() - 1;
        digits[i]++;
        cout << i << endl;
        while (digits[i] > 9) {
            cout << i << endl;
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                break;
            }
            i--;
            digits[i]++;
        }
        cout << i << endl;
        return digits;
    }
};