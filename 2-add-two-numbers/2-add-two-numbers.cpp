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
        
        ListNode* res = NULL;
        ListNode* p = NULL;
        
        int sum = 0, carry = 0;
        while(l1 && l2) {
            
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            if(res == NULL) {
                res = new ListNode(sum);
                p = res;
            }
            else {
                p->next = new ListNode(sum);
                p = p->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1) {
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            if(res == NULL) {
                res = new ListNode(sum);
                p = res;
            }
            else {
                p->next = new ListNode(sum);
                p = p->next;
            }
            l1 = l1->next;
        }
        
        while(l2) {
            sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            if(res == NULL) {
                res = new ListNode(sum);
                p = res;
            }
            else {
                p->next = new ListNode(sum);
                p = p->next;
            }
            l2 = l2->next;
        }
        
        if(carry) {
            if(res == NULL) {
                res = new ListNode(carry);
                p = res;
            }
            else {
                p->next = new ListNode(carry);
                p = p->next;
            }
        }
        
        return res;
    }
};