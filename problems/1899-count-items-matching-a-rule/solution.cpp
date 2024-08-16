class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int x = 0;
        for (auto a : items) {
            if (ruleKey == "color") {
                x += a[1] == ruleValue;
            } else if (ruleKey == "type") {
                x += a[0] == ruleValue;
            } else {
                x += a[2] == ruleValue;
            }
        }
        return x;
    }
};