class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string out;
        for (string s : strs) {
            int l = s.size();
            out += to_string(l) + "#" + s;  
        }
        return out;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> out;
        int x = 0;
        while (x < s.size()) {
            int n = 0;
            while (isdigit(s[x])) {
                n *= 10;
                n += s[x] - '0';
                x++;
            }
            // remove delim
            x++;
            out.push_back(s.substr(x, n));
            x+=n;
        }
        return out;
    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));