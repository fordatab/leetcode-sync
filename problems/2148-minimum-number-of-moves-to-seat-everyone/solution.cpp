class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        int out = 0;
        for (int x = 0; x < seats.size(); x++) {
            out += abs(seats[x]-students[x]);
        }
        return out;
    }
};