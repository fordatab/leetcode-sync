class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int out = 0;
        int c = capacity;
        for (int x = 0; x < plants.size(); x++) {
            if (plants[x] > c) {
                c = capacity;

                out += (2*x + 1);
            } else {
                            out++;

            }

            c -= plants[x];
            cout << out <<" " << c << endl;
        }
        return out;
    }
};