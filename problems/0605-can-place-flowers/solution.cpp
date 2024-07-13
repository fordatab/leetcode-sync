class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int x = 0; x < flowerbed.size(); x++) {
            if (flowerbed[x] == 1) {
                x++;
            } else {
                if (x + 1 == flowerbed.size()) {
                    n--;
                } else if (flowerbed[x+1] == 1) {
                    x+=2;
                } else {
                    n--;
                    cout << x << endl;
                    x++;
                }       
                
            }
        }
        return n <= 0;
    }
};