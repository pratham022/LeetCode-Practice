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
    ListNode* reverse(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        int n = count(head);
        int mid = (n / 2) + (n % 2);
        
        // [1, 2, 1, 2, 1]
        ListNode* p = head;
        for(int i=0; p && i<mid-1; i++) {
            p = p->next;
        }
        p->next = reverse(p->next);
        
        ListNode* q = p->next;
        p = head;
        
        while(p && q) {
            if(p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        return true;
        
        
    }
};