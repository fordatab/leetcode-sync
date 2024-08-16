class Solution {
public:
    string interpret(string command) {
        string out;
        for (int x= 0; x < command.size(); x++) {
            if (command[x] == 'G') {
                out += 'G';
                continue;
            }
            if (command[x] == '(') {
                if (command[x+1] == ')') {
                    out += 'o';
                    x++;
                } else {
                    out += "al";
                    x+=2;
                }
            }
        }
        return out;
    }
};