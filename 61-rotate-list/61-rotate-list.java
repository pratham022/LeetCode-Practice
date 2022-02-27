/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    int count(ListNode head) {
        int cnt = 0;
        while(head != null) {
            cnt++;
            head = head.next;
        }
        return cnt;
    }
    public ListNode rotateRight(ListNode head, int k) {
        
        int n = count(head);
        if(n == 0)
            return null;
        
        k = k % n;
        if(k == 0)
            return head;
        int iterations = n - k;
        
        ListNode p = head;
        ListNode prev = null;
        
        while(p != null && iterations > 0) {
            prev = p;
            p = p.next;
            iterations--;
        }
        
        ListNode newHead = p;
        prev.next = null;
        
        while(p.next != null) {
            p = p.next;
        }
        p.next = head;
        
        return newHead;
        
        
    }
}