class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string out = "";
        vector<pair<int, char>> vals = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        
        while (a > 0 || b > 0 || c > 0) {
            auto m = max_element(vals.begin(), vals.end());
            int d = m->second;
            int n = m->first;
            
            // Smart character count for first character
            int firstCount = min(2, n);
            // If we have significantly more of this character, use 2; otherwise use 1
            pair<int, char> secondMax = {0, 'f'};
            for (int x = 0; x < 3; x++) {
                if (vals[x].second != d && vals[x].first > secondMax.first) {
                    secondMax.first = vals[x].first;
                    secondMax.second = vals[x].second;
                }
            }
            if (secondMax.first > 0 && n < secondMax.first + 2) {
                firstCount = 1;
            }
            
            out += string(firstCount, d);
            m->first -= firstCount;
            
            pair<int, char> add = {0, 'f'};
            for (int x = 0; x < 3; x++) {
                if (vals[x].second != d) {
                    if (vals[x].first > add.first) {
                        add.first = vals[x].first;
                        add.second = vals[x].second;
                    }
                }
            }  
            if (add.first == 0) {
                return out;
            }
            
            // Smart character count for second character
            int secondCount = min(2, add.first);
            // Use 1 if the difference isn't big enough to justify 2
            if (add.first < m->first + 2) {
                secondCount = 1;
            }
            
            out += string(secondCount, add.second);
            for (int x = 0; x < 3; x++) {
                if (vals[x].second == add.second) {
                    vals[x].first -= secondCount;
                }
            }
            
            a = vals[0].first;
            b = vals[1].first;
            c = vals[2].first;
        } 
        return out;
    }
};