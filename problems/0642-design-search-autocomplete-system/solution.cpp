class AutocompleteSystem {
public:
    struct TrieNode {
        unordered_set<string> words;
        map<char, TrieNode*> children;
        int ct;
    };
    TrieNode* root;
    TrieNode* reset; 
    unordered_map<string, int> mp;
    string currentInput;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        reset = root;
        int i = 0;
        for (auto sentence : sentences) {
            TrieNode* curr = root;
            for (auto c : sentence) {
                if (curr->children[c] == nullptr) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
                curr->words.insert(sentence);

            }
            curr->ct = times[i];
            mp[sentence] = times[i];
            i++;
        }
        
    }
    vector<string> topThree(const unordered_map<string, int>& sentenceFreq, unordered_set<string>& sentences) {
    // Min-heap: smallest element at top (so we can pop it when size > 3)
    auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second; // Higher frequency should be "smaller" in min-heap
        }
        return a.first < b.first; // Lexicographically smaller should be "larger"
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
    
    for (const auto& [sentence, freq] : sentenceFreq) {
        if (sentences.find(sentence) != sentences.end()) {
            pq.push({sentence, freq});
            if (pq.size() > 3) {
                pq.pop(); // Remove the "smallest" (least hot)
            }
        }
    }
    
    // Extract results and reverse to get correct order
    vector<string> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}


vector<string> input(char c) {
    if (c == '#') {
        mp[currentInput]++; // This handles both new and existing sentences
        
        // Insert into trie
        TrieNode* curr = reset;
        for (char ch : currentInput) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
            curr->words.insert(currentInput);
        }
        
        currentInput = "";
        return {};
    }
    
    currentInput += c;
    
    // Always traverse from root based on currentInput
    TrieNode* curr = reset;
    bool validPrefix = true;
    for (char ch : currentInput) {
        if (curr->children.find(ch) == curr->children.end()) {
            validPrefix = false;
            break;
        }
        curr = curr->children[ch];
    }
    
    if (!validPrefix) {
        return {};
    }
    
    return topThree(mp, curr->words);
}
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */