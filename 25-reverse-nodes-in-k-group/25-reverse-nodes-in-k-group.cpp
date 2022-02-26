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
        int cnt = 0;
        while(head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* reverse(ListNode* head, int k) {
        
        if(head == NULL)
            return NULL;
        
        int forwardLen = count(head);
        if(forwardLen < k)
            return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int cnt = k;
        
        while(curr && cnt) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
            cnt--;
        }
        
        head->next = reverse(next, k);
        
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head, k);
    }
};