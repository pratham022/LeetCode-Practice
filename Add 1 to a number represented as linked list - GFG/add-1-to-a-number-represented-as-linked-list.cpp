// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* addOne(Node *head) {
        
        // reverse the list
        Node* revHead = reverse(head);
        
        // now start adding 1
        int sum = 0;
        int carry = 1;
        
        Node* p = revHead;
        Node* prev = NULL;
        while(p != NULL) {
            
            sum = p->data + carry;
            
            // calculate sum and next carry
            carry = sum / 10;
            sum = sum % 10;
            
            // set p->data as sum
            p->data = sum;
            
            // advance the pointers
            prev = p;
            p = p->next;
        }
        
        if(carry) {
            // after traversing the list, if carry remains then append it to the end
            Node* t = new Node(carry);
            prev->next = t;
        }
        
        // again reverse the list
        head = reverse(revHead);
        
        return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends