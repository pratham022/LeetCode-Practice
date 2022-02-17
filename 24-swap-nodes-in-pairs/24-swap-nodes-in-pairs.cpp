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
    ListNode* reverse(ListNode* head, int k) {
        
        // base case
        if(head == NULL)
            return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        int count = 0;
        
        /*reverse first k nodes of the linked list */
        while(curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
            count++;
        }
         
        /* next is now a pointer to (k+1)th node
        Recursively call for the list starting from current.
        And make rest of the list as next of first node */
        if(next != NULL)
            head->next = reverse(next, k);
        
        /* prev is new head of the input list */
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        
        return reverse(head, 2);
    }
};