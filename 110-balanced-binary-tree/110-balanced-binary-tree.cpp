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
    int height(TreeNode* root, bool &flag) {
        if(root == NULL)
            return 0;
        
        int leftHeight = height(root->left, flag);
        int rightHeight = height(root->right, flag);
        
        int diff = abs(leftHeight - rightHeight);
        if(diff > 1)
            flag = false;
        
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        height(root, flag);
        
        return flag;
    }
};