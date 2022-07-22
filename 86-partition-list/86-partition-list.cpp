/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = new ListNode(101);
        ListNode* afterHead = new ListNode(101);
        
        ListNode* p = head;
        ListNode* bp = beforeHead;
        ListNode* ap = afterHead;
        
        while(p != NULL) {
            if(p->val < x) {
                bp->next = p;
                bp = bp->next;
            }
            else {
                ap->next = p;
                ap = ap->next;
            }
            p = p->next;
        }
        
        bp->next = NULL;
        ap->next = NULL;
        
        ListNode* finalHead = NULL;
        if(bp->val == 101 && ap->val == 101) {}
        else if(bp->val == 101)
            finalHead = afterHead->next;
        else if(ap->val == 101)
            finalHead = beforeHead->next;
        else {
            bp->next = afterHead->next;
            finalHead= beforeHead->next;
        }
        
        return finalHead;
    }
};