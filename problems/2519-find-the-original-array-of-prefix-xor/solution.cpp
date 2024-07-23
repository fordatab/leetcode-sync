class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int x = 0;
        for (int a = 0; a < pref.size(); a++) {
            cout << pref[a];

            pref[a] = pref[a] ^ x;
                        x ^= pref[a];
        }
        return pref;
    }
};