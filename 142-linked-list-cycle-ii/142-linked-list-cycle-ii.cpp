/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* hare = head;
        ListNode* turtle = head;
        bool cycleExists = false;
        
        while(hare && turtle && hare->next) {
            hare = hare->next->next;
            turtle = turtle->next;
            
            if(hare == turtle) {
                cycleExists = true;
                break;
            }
        }
        
        if(cycleExists) {
            hare = head;
            if(hare == turtle)
                return hare;
            
            while(hare && turtle) {
                hare = hare->next;
                turtle = turtle->next;
                if(hare == turtle)
                    return hare;
            }
        }
        return NULL;
    }
};