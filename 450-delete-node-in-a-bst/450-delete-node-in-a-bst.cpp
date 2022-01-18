/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteRecursive(TreeNode* root, int key) {
        
        // key not found...return
        if(root == NULL)
            return NULL;
        
        // search for key in left 
        else if(key < root->val) {
            root->left = deleteRecursive(root->left, key);
            return root;
        }
        
        // search for key in right
        else if(key > root->val) {
            root->right = deleteRecursive(root->right, key);
            return root;
        }
        
        else {
            // key found
            
            // node is a leaf node...simply delete it and return NULL
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            
            // node has only one child...return its child and delete that node
            else if(root->left == NULL) {
                TreeNode* p = root->right;
                delete root;
                return p;
            }
            else if(root->right == NULL) {
                TreeNode* p = root->left;
                delete root;
                return p;
            }
            
            // node has both children...go into the right subtree and then keep moving 
            // in the left...We are finding inorder successor in this case
            
            // replace this node with the root node to be deleted...
            // after replacing, delete this inorder successor node
            else {
                TreeNode* p = root->right;
                while(p->left != NULL)
                    p = p->left;
                
                root->val = p->val;
                root->right = deleteRecursive(root->right, root->val);
                return root;
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteRecursive(root, key);
    }
};