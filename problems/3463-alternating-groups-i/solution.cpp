class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int x = 0;
        int y = 1;
        int z = 2;
        int size = colors.size();
        int count = 0;
        while (x < size) {
            if (colors[x] && colors[z%size] && !colors[y%size]) {
                count++;
            }
            if (!colors[x] && !colors[z%size] && colors[y%size]) {
                count++;
            }
            x++;
            y++;
            z++;
        }
        return count;
    }
};