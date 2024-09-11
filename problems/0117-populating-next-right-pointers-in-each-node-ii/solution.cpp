// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}
//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* current = root;
        Node* nextLevelStart = nullptr;
        Node* prev = nullptr;
        
        while (current) {
            // Process current level
            while (current) {
                // Connect left child
                if (current->left) {
                    if (prev) {
                        prev->next = current->left;
                    } else {
                        nextLevelStart = current->left;
                    }
                    prev = current->left;
                }
                
                // Connect right child
                if (current->right) {
                    if (prev) {
                        prev->next = current->right;
                    } else {
                        nextLevelStart = current->right;
                    }
                    prev = current->right;
                }
                
                // Move to next node
                current = current->next;
            }
            
            // Move to next level
            current = nextLevelStart;
            nextLevelStart = nullptr;
            prev = nullptr;
        }
        
        return root;
    }
};