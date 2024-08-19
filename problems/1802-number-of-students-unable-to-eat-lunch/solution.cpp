class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int i = 0;
        for (auto a : students) {
            q.push(a);
        }
        bool take = true;;
        while (q.size() && take) {
            int sz = q.size();
            cout << sz << endl;
            take = false;
            for (int x = 0; x < sz; x++) {
                cout << q.front() << " " << sandwiches[i] << endl;
                if (q.front() == sandwiches[i]) {
                    take = true;
                    q.pop();
                    i++;
                } else {
                    q.push(q.front());
                    q.pop();
                }

            }
        }
        return q.size();
    }
};