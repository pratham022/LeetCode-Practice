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
    void flatten(TreeNode* root, TreeNode* &prev) {
        if(root == NULL)
            return;
        
        flatten(root->right, prev);
        root->right = prev;
        
        TreeNode* left = root->left;
        root->left = NULL;
        prev = root;
        
        flatten(left, prev);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* prev = NULL;
        flatten(root, prev);
        return prev;
    }
};