class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int n = customers.size();
        for (int x = 0; x < n; x++) {
            if (!grumpy[x]) {
                sum += customers[x];
            }
        }
        int cur = 0;
        for (int x = 0; x < minutes; x++) {
            if (grumpy[x]) {
                sum += customers[x]; 
            }
            
        }
        int out = sum;
        for (int y = minutes; y < n; y++) {
            if (grumpy[y - minutes]) {
                sum -= customers[y - minutes]; 
            }
            if (grumpy[y]) {
                sum += customers[y];

            }
            out = max(out, sum);
        }
        return out;
    }
};