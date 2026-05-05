class Solution {
public:
    int countPrimes(int n) {
        static const int MAX_N = 5000000;
        static vector<int> primeCount = []() {
            vector<bool> isPrime(MAX_N + 1, true);
            vector<int> count(MAX_N + 1, 0);

            isPrime[0] = isPrime[1] = false;

            for (int i = 2; i * i <= MAX_N; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j <= MAX_N; j += i) {
                        isPrime[j] = false;
                    }
                }
            }

            for (int i = 2; i <= MAX_N; i++) {
                count[i] = count[i - 1] + (isPrime[i] ? 1 : 0);
            }

            return count;
        }();
        
        return n <= 2 ? 0 : primeCount[n - 1];
    }
};