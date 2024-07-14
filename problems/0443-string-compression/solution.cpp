class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('\0');
        char c = chars[0];
        int count = 1;
        vector<char> out;
        int index = 0;
        for (int x = 1; x < chars.size(); x++) {
            if (c == chars[x]) {
                count++;
            } else if (count == 1) {
                chars[index] = c;
                index++;
                c = chars[x];

            } else {
                chars[index] = c;
                                index++;

                c = chars[x];
                string cp = to_string(count);
                count = 1;
                cout << cp << endl;
                while (!cp.empty()) {

                                                        cout << index << endl;

                    chars[index] = cp[0];
                    cp.erase(cp.begin());
                                        index++;

                }
            }
        }
        return index;
    }
};