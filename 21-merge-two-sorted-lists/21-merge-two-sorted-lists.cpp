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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        ListNode* headNew = NULL;
        ListNode* p = NULL;
        
        while(list1 && list2) {
            
            if(list1->val < list2->val) {
                if(headNew == NULL) {
                    headNew = list1;
                    p = headNew;
                }
                else {
                    p->next = list1;
                    p = p->next;
                }
                list1 = list1->next;
            }
            else {
                if(headNew == NULL) {
                    headNew = list2;
                    p = headNew;
                }
                else {
                    p->next = list2;
                    p = p->next;
                }
                list2 = list2->next;
            }
        }
        
        while(list1) {
            p->next = list1;
            p = p->next;
            list1 = list1->next;
        }
        while(list2) {
            p->next = list2;
            p = p->next;
            list2 = list2->next;
        }
        
        return headNew;
    }
};