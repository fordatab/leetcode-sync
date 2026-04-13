class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        } 
        for (auto [a, b] : m) {
            pq.push({b, a});
            // cout << a << " " << b << endl; 
        }  
        string out = ".";
        for (int i = 0; i < s.size(); i++) {
            auto [ct, ch] = pq.top();
            pq.pop();
            if (out.back() != ch) {
                out.push_back(ch);
                if (ct > 1) {
                    pq.push({ct - 1, ch});

                }
            } else {
                if (pq.empty()) {
                    return "";

                }
                auto [ct2, ch2] = pq.top();
                pq.pop();
                out.push_back(ch2);
                if (ct2 > 1) {
                    pq.push({ct2 - 1, ch2});
                }
                pq.push({ct, ch});
            }
            // cout << out << endl; 
        }
        return out.substr(1);

    }
};