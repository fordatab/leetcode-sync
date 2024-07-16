class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        for (int x = 1; x < gain.size(); x++) {
            gain[x] += gain[x-1];
        }
        int a = *max_element(gain.begin(), gain.end());
        return a < 0 ? 0 : a;
    }
};