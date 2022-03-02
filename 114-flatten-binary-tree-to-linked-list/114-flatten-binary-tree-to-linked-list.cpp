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
    void helperFlatten(TreeNode* root, TreeNode* &prev) {
        if(root == NULL)
            return;
        helperFlatten(root->right, prev);
        helperFlatten(root->left, prev);
        
        root->right = prev;
        prev = root;
        root->left = NULL;
        
    }
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        helperFlatten(root, prev);
    }
};