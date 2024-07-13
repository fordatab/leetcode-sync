class Solution {
public:
    string getEncryptedString(string s, int k) {
        char out[s.size()+1];
        for (int x = 0; x < s.size(); x++) {
            out[x] = s[(x+k)%s.size()];
        }
        out[s.size()] = '\0'; 
        return string(out);
    }
};