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
        
        unordered_map<Node*, Node*> mp;
        
        Node* p = head;
        Node* newHead = NULL;
        Node* q = NULL;
        
        while(p != NULL) {
            Node* newNode = new Node(p->val);
            mp[p] = newNode;
            
            if(newHead == NULL) {
                newHead = newNode;
                q = newHead;
            }
            else {
                q->next = newNode;
                q = q->next;
            }
            
            p = p->next;
        }
        
        p = head;
        while(p != NULL) {
            Node* oldRandom = p->random;
            Node* newRandom = mp[oldRandom];
            Node* newNode = mp[p];
            newNode->random = newRandom;
            
            p = p->next;
        }
        
        return newHead;
    }
};