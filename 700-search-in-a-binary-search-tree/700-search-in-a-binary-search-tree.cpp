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
    TreeNode* helper(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        
        int curr = root->val;
        if(curr == val)
            return root;
        
        if(val < curr)
            return helper(root->left, val);
        else
            return helper(root->right, val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return helper(root, val);
    }
};