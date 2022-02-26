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
    int count(ListNode* head) {
        int cnt = 0;
        while(head != NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int n = count(headA);
        int m = count(headB);
        
        while(headA && n > m) {
            headA = headA->next;
            n--;
        }
        while(headB && m > n) {
            headB = headB->next;
            m--;
        }
        
        // start iterating both of the ptrs simultaneously to get intersection
        while(headA && headB) {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};