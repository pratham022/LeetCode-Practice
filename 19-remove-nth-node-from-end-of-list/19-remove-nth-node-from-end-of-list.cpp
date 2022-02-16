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
    int count(ListNode* head) {
        ListNode* p = head;
        int cnt = 0;
        while(p) {
            cnt++;
            p = p->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = count(head);
        
        // nth node from the end = (len - n + 1)th from beginning
        
        int k = len - n;
        
        ListNode* p = head;
        ListNode* prev = NULL;
        
        while(p && k--) {
            prev = p;
            p = p->next;
        }
        
        if(prev == NULL) {
            // we have to remove the head node here
            head = head->next;
            delete p;
        }
        else {
            prev->next = p->next;
            delete p;
        }
        return head;
        
    }
};