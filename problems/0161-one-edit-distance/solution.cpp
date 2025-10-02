class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (abs((int)s.size() - (int)t.size()) > 1) {
            return false;
        } else if (s.size() - t.size() == 0) {
            bool changed = false;
            for (int x = 0; x < s.size(); x++) {
                if (s[x] != t[x]) {
                    if (changed) {
                        return false;
                    } else {
                        changed = true;
                    }
                }
            }
            return changed;
        } else {
            if (s.size() > t.size()) {
                swap(s, t);
            }
            int a = 0;
            int b = 0;
            bool changed = false;
            while (b < t.size()) {
                if (s[a] != t[b]) {
                    if (changed) {
                        return false;
                    } else {
                        a--;
                        changed = true;
                    }
                }
                a++;
                b++;
            }
            return true;
        }
    }
};