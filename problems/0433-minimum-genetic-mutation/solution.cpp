class Solution {
public:
    int minMutation(string beginWord, string endWord, vector<string>& wordList) {
                // Add beginWord to wordList if it's not already there
        wordList.push_back(beginWord);
        
        // Create adjacency list
        unordered_map<string, vector<string>> adj;
        for (const string& word : wordList) {
            for (int i = 0; i < word.length(); i++) {
                string pattern = word;
                pattern[i] = '*';
                adj[pattern].push_back(word);
            }
        }
        
        // BFS
        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        int level = 0;
        
        while (!q.empty()) {
            int size = q.size();
            level++;
            
            for (int i = 0; i < size; i++) {
                string currentWord = q.front();
                q.pop();
                
                if (currentWord == endWord) {
                    return level - 1;
                }
                
                for (int j = 0; j < currentWord.length(); j++) {
                    string pattern = currentWord;
                    pattern[j] = '*';
                    
                    for (const string& neighbor : adj[pattern]) {
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        
        return -1;  // No transformation sequence found
    }
};


