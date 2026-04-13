class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> types;
        int out = 0;
        int l = 0;
        for (int r = 0; r < fruits.size(); r++) {
            // if (types.size() < 3) {
                
            // }
            types[fruits[r]]++;
            while (types.size() > 2) {
                types[fruits[l]]--;
                if (types[fruits[l]] == 0) {
                    types.erase(fruits[l]);
                }
                l++;
            }
                            out = max(out, r - l + 1);

        } 
        return out;
    }
};