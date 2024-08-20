class Solution {
private:
    int mod(int x, int m) {
        return (x%m + m)%m;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        bool out = false;
        for (int x = 0; x < nums.size(); x++) {
            cout << endl;
            int c = 0;
            int f = x;
            int s = x;
            do {
                f = mod(f + nums[f], n);
                f = mod(f + nums[f], n);
                s = mod(s + nums[s], n);
            } while (f != s);
            cout << f << " " << s << endl;
            bool pos = true;
            bool neg = true;
            do {
                f = mod(f + nums[f], n);
                f = mod(f + nums[f], n);
                s = mod(s + nums[s], n);
                cout << nums[f] << " " << nums[s] << endl;
                if (nums[s] > 0) {
                    neg = false;
                } else {
                    pos = false;
                }
                    // pos &= (nums[s] > 0);
                    // neg &= !(nums[s] > 0);
                c++;
            } while (f != s);
            cout << neg << " " << pos << endl;
            if (c > 1 && (pos ^ neg)) {
                return true;
            }
        }
        return false;
    }
};