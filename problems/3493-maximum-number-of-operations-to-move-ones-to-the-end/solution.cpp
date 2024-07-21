class Solution {
public:
    int maxOperations(string s) {
        int ct = 0;
        int start = s.size()-1;
        while (start > -1 && s[start] == '1') {
            start--;
        }
        stack<int> idx;
        for (int x = start; x > -1; x--) {
            if (s[x] == '1') {
                idx.push(x);
            }
        }
        // while (!idx.empty()) {
        //     cout << idx.top() << endl;
        //     idx.pop();
        // }
        int total = 0;
        int group_size = 0;
        while (!idx.empty()) {
            int group = 0;
            int i = idx.top();
            group++;
            idx.pop();
            while (!idx.empty() && idx.top() == i + 1) {
                i++;
                idx.pop();
                group++;
            }
            group_size+=group;
            total+=group_size;
        }
        return total;
    }
};