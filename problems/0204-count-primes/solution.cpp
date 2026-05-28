class Solution {
public:
    int countPrimes(int n) {
<<<<<<< HEAD
        if (n <= 2) {
            return 0;
        }

        vector<bool> numbers(n, true);  // Initialize vector with n true values
        for (int p = 2; p <= sqrt(n); ++p) {
            if (numbers[p]) {
                for (int j = p * p; j < n; j += p) {
                    numbers[j] = false;
                }
            }
        }

        int numberOfPrimes = 0;
        for (int i = 2; i < n; i++) {
            if (numbers[i]) {
                ++numberOfPrimes;
            }
        }

        return numberOfPrimes;
=======
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
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
    }
};