class Solution {
public:
    bool isvowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    int countVowelSubstrings(string word) {
        int n = word.size();
        unordered_map<char,int> freq;
        int ans = 0;

        int L1 = 0, L2 = 0; // L2 ensures "all vowels"
        int cnt = 0;        // # of distinct vowels in window

        for (int R = 0; R < n; R++) {
            // Reset on consonant
            if (!isvowel(word[R])) {
                freq.clear();
                cnt = 0;
                L1 = L2 = R+1;
                continue;
            }

            // Add current vowel
            if (++freq[word[R]] == 1)
                cnt++;

            // Move L2 until window has all 5 vowels
            while (cnt == 5) {
                freq[word[L2]]--;
                if (freq[word[L2]] == 0)
                    cnt--;
                L2++;
            }

            // Move L1 to remove initial garbage—ensure window only vowels
            // (Already guaranteed since consonants reset everything)

            // Number of valid substrings ending at R
            ans += L2 - L1;
        }

        return ans;
    }
};
