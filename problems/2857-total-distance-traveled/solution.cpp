class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int out = 0;
        while (mainTank) {
            if (mainTank >= 5 && additionalTank) {
                out += 5 * 10;
                mainTank-=5;
                mainTank++;
                additionalTank--;
            } else if (mainTank < 5 || !additionalTank) {
                out += mainTank * 10;
                mainTank = 0;
            }
            cout << out << endl;
        }
        return out;
    }
};