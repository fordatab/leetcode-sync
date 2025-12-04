class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int out = 0;
        while (l <= r) {
            int weight = 0;
            weight += people[r];
            r--;
            cout << weight << endl;
            if (l <= r and weight + people[l] <= limit) {
                weight += people[l];
                l++;
            }
            cout << r << " " << l << endl;
            out++;
        }
        return out;
    }
};