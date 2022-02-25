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
        ListNode* p = head;
        
        while(p != NULL) {
            cnt++;
            p = p->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        
        int n = count(head);
        
        ListNode* mid = head;
        
        for(int i=0; mid && i<n/2; i++) {
            mid = mid->next;
        }
        return mid;
    }
};