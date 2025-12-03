class Solution {
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> ten = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    // convert a chunk of 3 digits to string version
    string convert(int num) {
        string o;
        int hundreds = num / 100;
        if (hundreds > 0) {
            // cout << hundreds << endl;
            // return {};
            o += ones[hundreds] + " Hundred";
        }  
        num %= 100; 
        int ts = num / 10;
        if (ts > 0) {
            if (ts == 1) {
                num %= 10;
                if (o.empty()) {
                    o = ten[num];
                } else {
                    o += " " + ten[num];

                }
                return o;
            } else {
                if (o.empty()) {
                o = tens[ts];

                } else {
                o += " " + tens[ts];

                }
            }
        }
        num %= 10;
        if (o.empty() or num == 0) {
            o += ones[num];
        } else {
        o += " " + ones[num];

        }
        return o;
    }
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        vector<string> units = {"", "Thousand", "Million", "Billion"};
        string out; 
        int i = 0;
        while (num) {
            int last_three = num % 1000;
            if (last_three == 0) {
                // skip
            } else {
                string part = convert(last_three);
                if (units[i].size()) {
                    part += " " + units[i];
                }
                if (out.size()) {
                    out = part + " " + out;
                } else {
                    // no space because empty
                    out = part;
                }
            }
            num /= 1000;
            i++;
        }
        return out;
    }
};