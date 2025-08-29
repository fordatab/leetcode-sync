class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int out = 0;
        for (int x = 0; x < words.size(); x++) {
            for (int y = x + 1; y < words.size(); y++) {
                if (words[x].size() <= words[y].size()) {
                    bool t = true;
                    if (words[x] != words[y].substr(0, words[x].size())) {
                        t = false;
                    }
                    string suffix = words[y];
                    if (words[x] != suffix.substr(suffix.size() - words[x].size() )) {
                        t = false;
                    }
                    out += t; 
                }

            }
        }
        return out;
    }
};