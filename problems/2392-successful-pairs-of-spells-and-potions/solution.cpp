class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> out;
        sort(begin(potions), end(potions));
        for (int x = 0; x < spells.size(); x++) {
            int l = 0;
            int r = potions.size() - 1;
            while (l <= r) {
                int mid = (r - l)/2 + l;
                // cout << mid << endl;
                long long s = (long)potions[mid] * spells[x];
                if (s >= success) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            out.push_back(potions.size() - l);
        }
        return out;
    }
};