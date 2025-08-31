class Solution {
public:
    const int ALPHABET_SIZE = 10; // May change for different character sets
    
    struct TrieNode {
        TrieNode *children[10]{};
        bool isEndOfWord;
        // Sometimes you might add other fields here, like `int wordCount;`
    
        TrieNode() {
            isEndOfWord = false;
            for (auto & i : children) {
                i = nullptr;
            }
        }
    };
    void insert(TrieNode* root, const int& in) {
        string key = to_string(in);
        TrieNode* pCrawl = root;
        for (char c : key) {
            int index = c - '0'; // The logic to get an index might change
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = new TrieNode();
            }
            pCrawl = pCrawl->children[index];
                    pCrawl->isEndOfWord = true;

        }
        pCrawl->isEndOfWord = true;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        auto* root = new TrieNode();
        for (int a : arr1) {
            insert(root, a);
        }
        int longest = 0;

        for (int a : arr2) {
            auto cur = root;
            string prefixes = to_string(a);
            int i = 1;
            for (char c : prefixes) {
                if (cur->children[c-'0'] == nullptr) {
                    break;
                }
                cur = cur->children[c-'0'];
                if (cur->isEndOfWord) {
                    longest = max(longest, i);
                }
                i++;
            }
        }
        return longest;
    }
};