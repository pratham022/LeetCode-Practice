/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        
        Node newHead = null;
        Node q = null;
        HashMap<Node, Node> mp = new HashMap<>();
        
        // p ptr is for old list while q ptr is for new list
        Node p = head;
        
        // populate the next pointers of the new list
        while(p != null) {
            
            Node t = new Node(p.val);
            mp.put(p, t);
            
            // insert this node into the new linked list
            if(newHead == null) {
                newHead = t;
                q = newHead;
            }
            else {
                q.next = t;
                q = q.next;
            }
            
            p = p.next;
        }
        
        p = head;
        while(p != null) {
            
            Node oldRandom = p.random;
            Node newRandom = mp.get(oldRandom);
            
            Node newNode = mp.get(p);
            
            newNode.random = newRandom;
            
            p = p.next;
            
        }
        
        return newHead;
        
    }
}