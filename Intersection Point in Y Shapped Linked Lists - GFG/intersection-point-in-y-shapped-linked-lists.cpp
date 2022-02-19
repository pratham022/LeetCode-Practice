// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

int count(Node* head) {
    int c = 0;
    Node* p = head;
    
    while(p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

int helper(Node* head1, Node* head2, int diff) {
    Node* p = head1;
    Node* q = head2;
    
    for(int i=0;i<diff;i++) {
        if(p == NULL)
            return -1;
        p = p->next;
    }
    while(p!=NULL && q!=NULL) {
        if(p == q)
            return p->data;
        p = p->next;
        q = q->next;
    }
    return -1;
}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2) {
    
    int n = count(head1);
    int m = count(head2);
    
    if(n >= m) {
        int diff = n - m;
        return helper(head1, head2, diff);
    }
    else {
        int diff = m - n;
        return helper(head2, head1, diff);
    }
    
}

