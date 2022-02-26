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
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        bool cycleExists = false;
        
        while(fast && fast->next && slow) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow) {
                cycleExists = true;
                break;
            }
        }
        
        if(cycleExists) {
            fast = head;
            if(fast == slow)
                return fast;
            
            while(fast && slow) {
                fast = fast->next;
                slow = slow->next;
                
                if(fast == slow)
                    return fast;
            }
        }
        
        return NULL;
    }
};