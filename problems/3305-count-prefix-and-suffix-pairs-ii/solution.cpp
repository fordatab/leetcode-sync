#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    // Memory-optimized TrieNode using a hash map.
    struct TrieNode {
        // The map's key is the character-pair index (0-675).
        // The value is the pointer to the child node.
        std::unordered_map<int, TrieNode*> children;
        int count = 0;
    };

    long long countPrefixSuffixPairs(std::vector<std::string>& words) {
        TrieNode* root = new TrieNode();
        long long ans = 0;

        for (const std::string& w : words) {
            TrieNode* curr = root;
            int n = w.length();

            // Search Phase: Remains the same logic.
            for (int i = 0; i < n; ++i) {
                int prefix_char = w[i] - 'a';
                int suffix_char = w[n - 1 - i] - 'a';
                int index = prefix_char * 26 + suffix_char;

                // Use map's .find() to check for a child's existence.
                if (curr->children.count(index)) {
                    curr = curr->children[index];
                    ans += curr->count;
                } else {
                    break; // Path does not exist.
                }
            }

            // Insertion Phase: Modified to use map operations.
            curr = root;
            for (int i = 0; i < n; ++i) {
                int prefix_char = w[i] - 'a';
                int suffix_char = w[n - 1 - i] - 'a';
                int index = prefix_char * 26 + suffix_char;
                
                // If the child doesn't exist, create it.
                if (!curr->children.count(index)) {
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
            curr->count++;
        }
        return ans;
    }
};