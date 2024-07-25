class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }
        vector<string> out;
        string res;
        dfs(out, digits, res);
        return out;
    }
    void dfs(vector<string>& out, string digits, string& res) {
        if (digits == "") {
            out.push_back(res);
        }
        int x = digits[0] - '0';
        switch (x) {
            case 2:
                res.push_back('a');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('b');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('c');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                break;
            case 3:
                res.push_back('d');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('e');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('f');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                                break;

            case 4:
                res.push_back('g');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('h');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('i');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                                break;

            case 5:
                res.push_back('j');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('k');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('l');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                break;

            case 6:
                res.push_back('m');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('n');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('o');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                break;

            case 7:
                res.push_back('p');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('q');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('r');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('s');
                dfs(out, digits.substr(1), res);
                res.pop_back();

                                break;

            case 8:
                res.push_back('t');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('u');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('v');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                                break;

            case 9:
                            res.push_back('w');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('x');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('y');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                res.push_back('z');
                dfs(out, digits.substr(1), res);
                res.pop_back();
                                break;

            default:
                break;
        }

    }
};