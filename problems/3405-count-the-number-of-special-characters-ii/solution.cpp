class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<int, int>> map(26);

        for (char c : word) {
            if ('a' <= c and c <= 'z') {
                if ((map[c-'a'].second > 0) or (map[c-'a'].first == -1)) {
                    map[c-'a'].first = -1;
                } else {
                    map[c-'a'].first = 1; 
                }
            }
            if ('A' <= c and c <= 'Z') {
                map[c-'A'].second = 1; 
            }
        }
        int ct = 0;
        for (auto p : map) {
            if ((p.first == 1) and p.second) {
                ct++;
            }
        }
        return ct;    
    }
};