/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        // Start with the root node
        Node* levelStart = root;
        
        // Continue until we reach a leaf node
        while (levelStart->left) {
            Node* cur = levelStart;
            
            while (cur) {
                // Connect left child to right child
                cur->left->next = cur->right;
                
                // Connect right child to left child of next node
                if (cur->next) {
                    cur->right->next = cur->next->left;
                }
                
                // Move to the next node in this level
                cur = cur->next;
            }
            
            // Move to the next level
            levelStart = levelStart->left;
        }
        
        return root;
    }
};