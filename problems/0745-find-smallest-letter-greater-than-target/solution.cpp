class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char t) {
        int l = 0;
        int r = letters.size()-1;
        while (l < r) {
            int mid = (r - l)/2 + l;
            if (letters[mid] > t) {
                r = mid;
            }
            if (letters[mid] <= t) {
                l = mid + 1;
            }
        }
                cout << l << " " << r << endl;

        if (l == letters.size()-1 && t >= letters[l]) {
            return letters[0];
        }
        return letters[l];
        // return letters[0];
    }
};