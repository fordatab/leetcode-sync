class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> out;
        int n = s.size();
        int p = 0;
        int i = 0;
        int pos = 0;
        while ((pos = s.find(a, i)) != string::npos) {
            int pos2 = s.find(b, max(0, pos - k));
            if ((pos2 != string::npos) and (abs(pos2 - pos) <= k)) {
                out.push_back(pos);

            }
            i = pos + 1;
        }
        return out;
    }
};