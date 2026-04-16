class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        for (char c : secret) {
            m[c]++;
        }
        int A = 0;
        unordered_map<char, int> m1;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                m[secret[i]]--;
                A++;
            } else {
                m1[guess[i]]++;
            }

        }  
        int B = 0;
        for (auto [a, b] : m1) {
            B += min(b, m[a]);
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};