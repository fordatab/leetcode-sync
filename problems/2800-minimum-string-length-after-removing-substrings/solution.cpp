class Solution {
public:
    int minLength(string s) {
        string out;
        for (char c : s) {
            if (!out.empty()) {
                cout << out.size() << endl;
                if (out.back() == 'A' && c == 'B') {
                    out.pop_back();
                    continue;
                }   
                            //     cout << out.size() << endl;
                            //  return -1;

                if (out.back() == 'C' && c == 'D') {
                    out.pop_back();
                    continue;
                }
            } 
                out.push_back(c);
            
        }
        return out.size();
    }
};