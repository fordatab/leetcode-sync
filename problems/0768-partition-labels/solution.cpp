class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> out;
        unordered_map<int, int> m;
        for (int x = s.size() - 1; x >= 0; x--) {
            if (m.find(s[x]-'a') == m.end()) {
                m[s[x]-'a'] = x;
            }
        }
        int x = 0;
        while (x < s.size()) {
            int o = 0;
            cout << s[x] << endl;
            int idx = m[s[x]-'a'];
            for (int i = x; i < idx; i++) {
                cout << m[s[i]-'a'] << endl;
                o = max(o, m[s[i]-'a']);
                idx = max(idx, o);
            }
            if (o == 0) {
                out.push_back(1);
                x++;
            } else {
                o++;
                cout << o << endl;
                out.push_back(o - x);
                x = o;
            }
 
            cout << x << endl;
            cout << o << endl;;
            // if (out.size() > 2) {
            //     break;
            // }
        }
        return out;
    }
};