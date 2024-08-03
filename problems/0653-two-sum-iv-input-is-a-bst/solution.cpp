/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
private:
    stack<TreeNode*> s;

    void push_l(TreeNode* node) {
        while (node) {
            s.push(node);
            node = node->left;
        }
    }

    void push_r(TreeNode* node) {
        while (node) {
            s.push(node);
            node = node->right;
        }
    }
public:
    BSTIterator(TreeNode* root, bool dir) {
        if (dir) {
        push_l(root);

        } else {
            push_r(root);
        }
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();
        push_l(node->right);
        return node->val;
    }

    int prev() {
        TreeNode* node = s.top();
        s.pop();
        push_r(node->left);
        return node->val;
    }
    
    
    bool hasNext() {
        return !s.empty();
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator in(root, true);
        BSTIterator rev(root, false);
        int i = in.next();
        int j = rev.prev();
        while (i < j) {
            if (i + j == k) {
                return true;
            } 
            if (i + j > k) {
                j = rev.prev();
            } else {
                i = in.next();
            }
        }
        return false;
    }
};