class Solution {
public:
    vector<int> toVec(int num) {
        vector<int> out;
        while (num) {
            out.push_back(num % 10);
            num /= 10;
        }
        reverse(out.begin(), out.end());
        return out;
    }

    int countPnV(vector<int> vec) {
        int ct = 0;
        for (int i = 1; i < vec.size() - 1; i++) {
            if (vec[i] > vec[i-1] and vec[i] > vec[i+1]) {
                ct++;
            }
            if (vec[i] < vec[i-1] and vec[i] < vec[i+1]) {
                ct++;
            }
        }
        return ct;
    }
    int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int i = num1; i <= num2; i++) {
            total += countPnV(toVec(i));
        }
        return total;
    }
};