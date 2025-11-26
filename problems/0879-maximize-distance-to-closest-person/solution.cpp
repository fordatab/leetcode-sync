class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = 0;
        int out = -1;
        for (int r = 0; r < seats.size(); r++) {
            // normal case
            if (seats[r] == 1) {
                if (out == -1) {
                    out = r;  
                    l = r; 
                } else {
                    out = max(out, (r - l)/2);
                    l = r; 
                }
            }
        }
        out = max(out, (int)seats.size() - (l + 1));
        return out;
    }
};