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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* p = l1;
        ListNode* q = l2;
        
        ListNode* res = NULL;
        ListNode* t = NULL;
        
        int sum = 0, carry = 0;
        
        while(p && q) {
            
            sum = p->val + q->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            if(res == NULL) {
                res = new ListNode(sum);
                t = res;
            }
            else {
                t->next = new ListNode(sum);
                t = t->next;
            }
            
            p = p->next;
            q = q->next;
        }
        
        while(p) {
            sum = p->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            if(res == NULL) {
                res = new ListNode(sum);
                t = res;
            }
            else {
                t->next = new ListNode(sum);
                t = t->next;
            }
            p = p->next;
        }
        
        while(q) {
            sum = q->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            if(res == NULL) {
                res = new ListNode(sum);
                t = res;
            }
            else {
                t->next = new ListNode(sum);
                t = t->next;
            }
            q = q->next;
        }
        
        if(carry) {
            if(res == NULL) {
                res = new ListNode(carry);
                t = res;
            }
            else {
                t->next = new ListNode(carry);
                t = t->next;
            }
        }
        
        return res;
    }
};