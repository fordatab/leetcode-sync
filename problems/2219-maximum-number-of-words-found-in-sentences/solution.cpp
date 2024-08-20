class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int m = 0;
        for (auto s : sentences) {
            int c = 1;
            for (auto cr : s) {
                c += (cr == ' ');
            }
            m = max(c, m);
        }
        return m;
    }
};