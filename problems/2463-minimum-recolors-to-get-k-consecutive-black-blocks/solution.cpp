class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int c = 0;
        int l = 0;
        int o = k;
        for (int x = 0; x < blocks.size(); x++) {
            cout << c << endl;
            if (blocks[x] == 'B') {
                c++;
            }
            o = min(k - c, o);
            if (x - l + 1 == k) {
                if (blocks[l] == 'B') {
                    c--;
                }
                l++;
            }
        }
        return o;
    }
};