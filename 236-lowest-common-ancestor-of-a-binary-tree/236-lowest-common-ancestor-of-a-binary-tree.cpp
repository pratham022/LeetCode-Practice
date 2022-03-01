/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root == p || root == q)
            return root;
        
        TreeNode* lAns = lca(root->left, p, q);
        TreeNode* rAns = lca(root->right, p, q);
        
        if(lAns == NULL && rAns == NULL)
            return NULL;
        else if(lAns != NULL && rAns == NULL)
            return lAns;
        else if(lAns == NULL && rAns != NULL)
            return rAns;
        else
            return root;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};