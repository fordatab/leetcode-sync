class Solution {
public:
    int maxPalindromesAfterOperations(std::vector<std::string>& words) {
        std::vector<int> charCounts(26, 0);
        std::vector<int> lengths;
        
        // 1. Collect character counts and string lengths
        for (const std::string& w : words) {
            lengths.push_back(w.length());
            for (char c : w) {
                charCounts[c - 'a']++;
            }
        }
        
        // 2. Count total available pairs
        int totalPairs = 0;
        for (int count : charCounts) {
            totalPairs += count / 2;
        }
        
        // 3. Sort lengths to satisfy the shortest strings first
        std::sort(lengths.begin(), lengths.end());
        
        // 4. Greedily form palindromes
        int maxPalindromes = 0;
        for (int len : lengths) {
            int pairsNeeded = len / 2;
            if (totalPairs >= pairsNeeded) {
                totalPairs -= pairsNeeded;
                maxPalindromes++;
            } else {
                // If we don't have enough pairs for this string, 
                // we won't have enough for any longer strings either.
                break;
            }
        }
        
        return maxPalindromes;
    }
};