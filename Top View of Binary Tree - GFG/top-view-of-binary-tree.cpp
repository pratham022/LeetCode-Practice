// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
            //         	1(0, 0)
            
            //  2(1, -1)            3(1, 1)
            
            // 4(2, -2)  5(2, 0) 6(2, 0)     7(2, 2)
            
            // (horizontalHeight, verticalHeight)
            
            // We see that the nodes with unique verticalHeights are taken
            // Also while travrsing in level order fashion, the first node with
            // the vertical height is taken into consideration
            
            vector<int> res;
            if(root == NULL)
                return res;
            
            map<int, int> mp;
            queue<pair<Node*, int>> q;
            q.push(make_pair(root, 0));
            
            while(!q.empty()) {
                
                pair<Node*, int> curr = q.front();
                q.pop();
                
                Node* p = curr.first;
                int vertLvl = curr.second;
                
                if(mp.find(vertLvl) == mp.end()) {
                    mp[vertLvl] = p->data;
                }
                
                if(p->left)
                    q.push(make_pair(p->left, vertLvl-1));
                
                if(p->right)
                    q.push(make_pair(p->right, vertLvl+1));
                
            }
            for(auto x : mp) {
                res.push_back(x.second);
            }
            return res;
    }

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends