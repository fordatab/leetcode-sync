class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        int t = 0;
        int i = 0;
        for (int x = 0; x < gas.size(); x++) {
            t += (gas[x] - cost[x]);
            if (t < 0) {
                t = 0;
                i = x + 1;
            }
        }
        return i;
    }
};
