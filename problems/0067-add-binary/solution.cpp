class Solution {
public:
    string addBinary(string a, string b) {
        int f;
        int s;
        int c = 0;
        string out;
        while (!a.empty() || !b.empty()) {
            if (a.empty()) {
                s = b.back()-'0';
                f = 0;
                b.pop_back();
            } else if (b.empty()) {
                f = a.back()-'0';
                s = 0;
                a.pop_back();
            } else {
                f = a.back()-'0';
                s = b.back()-'0';
                a.pop_back();
                b.pop_back();
            }
            cout << (f+s+c)%2 << endl;
            out.push_back((f+s+c)%2 + '0');
            c = (f+s+c)/2;
        }
        cout << f << " " << s  << " "  << c << endl;
        cout << (f+s+c)%2 << endl;
        if (c) {
        out.push_back(c+'0');

        }
        reverse(begin(out), end(out));
        return out;
    }
};