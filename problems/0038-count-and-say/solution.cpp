class Solution {
public:
    string countAndSay(int n) {
        string start = "1";
        for (int x = 2; x <= n; x++) {
            start.push_back('e');
            string tmp;
            int i = 0;
            int k = start.size() - 1;
            while (i < k) {
                // cout << k << endl;
                int l = 1;
                char  c= start[i];  
                while (start[i] != 'e' && start[i] == start[i+1]) {
                    l++;
                    i++;
                }  
                // i++;
                if (start[i] == 'e') break;
                // if (i + 1 == k) {
                //     l++;
                //     i++;
                // }
                i++;
                cout << l << " " << c <<  " "<< i << endl;
                tmp += to_string(l);
                tmp += c;
                // // i += l;
                // break;
            }
                            cout << tmp << endl;

            start = tmp;
        }
        return start;
    }
};