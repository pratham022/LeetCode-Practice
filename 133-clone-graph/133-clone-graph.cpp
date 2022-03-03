/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* curr, Node* node, vector<Node* > &visited) {
        
        visited[curr->val] = node;
        for(Node* ele : curr->neighbors) {
            if(visited[ele->val] == NULL) {
                Node* newNode = new Node(ele->val);
                (node->neighbors).push_back(newNode);
                dfs(ele, newNode, visited);
            }
            else 
                (node->neighbors).push_back(visited[ele->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        
        vector<Node* > visited(105, NULL);
        
        Node* copy = new Node(node->val);
        visited[node->val] = copy;
        
        for(Node* curr : node->neighbors) {
            
            int elem = curr->val;
            if(visited[elem] == NULL) {
                Node* newNode = new Node(elem);
                (copy->neighbors).push_back(newNode);
                dfs(curr, newNode, visited);
            }
            else {
                // node already visited
                (copy->neighbors).push_back(visited[elem]);
            }
        }
        
        return copy;
    }
};