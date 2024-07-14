/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes;
        nodes[nullptr] = nullptr;
        Node* a = head;
        while (a) {
            nodes[a] = new Node(a->val);
            a = a->next;
        }
        a = head;
        while (a) {
            nodes[a]->next = nodes[a->next];
            nodes[a]->random = nodes[a->random];
            a = a->next;
        }
        return nodes[head];        
    }
};
