class Solution {
public:
    // Mapping f(c): 'a','b','c'->1, 'd','e','f'->2, ..., 'x','y','z'->9
    int f(char c) {
        return 9 - (('z' - c) / 3);
    }

    int countDivisibleSubstrings(string word) {
        long long ans = 0;

        for (int avg = 1; avg <= 9; avg++) {
            int pref = 0;
            unordered_map<int, int> cnt;
            cnt[0] = 1;

            for (char c : word) {
                pref += f(c) - avg;
                ans += cnt[pref];
                cnt[pref]++;
            }
        }

        return (int)ans;
    }
};