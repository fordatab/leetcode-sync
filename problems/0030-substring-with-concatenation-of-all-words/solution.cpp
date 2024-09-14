class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLength = words[0].length();
        int totalWords = words.size();
        int windowLength = wordLength * totalWords;
        
        if (s.length() < windowLength) return result;
        
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        // Optimize by checking each possible starting position for words
        for (int i = 0; i < wordLength; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seenWords;
            
            for (int j = i; j <= s.length() - wordLength; j += wordLength) {
                string currentWord = s.substr(j, wordLength);
                
                if (wordCount.find(currentWord) != wordCount.end()) {
                    seenWords[currentWord]++;
                    count++;
                    
                    while (seenWords[currentWord] > wordCount[currentWord]) {
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLength;
                    }
                    
                    if (count == totalWords) {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLength;
                    }
                } else {
                    seenWords.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }
        
        return result;
    }
};