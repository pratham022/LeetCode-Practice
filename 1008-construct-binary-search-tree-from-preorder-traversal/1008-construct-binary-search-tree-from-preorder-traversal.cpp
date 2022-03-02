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

    TreeNode* helper(vector<int>& preorder, int ub, int &i) {
        if(i == preorder.size() || preorder[i] > ub)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        
        root->left = helper(preorder, root->val, i);
        root->right = helper(preorder, ub, i);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int ub = INT_MAX;
        int i = 0;
        
        return helper(preorder, ub, i);
        
    }
};