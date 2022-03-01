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
    int height(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
    int diameter(TreeNode* root) {   
        if(root == NULL)
            return 0;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        int leftDiameter = diameter(root->left);
        int rightDiameter = diameter(root->right);
        
        int pathThroughRoot = leftHeight + rightHeight + 1;
        int pathNotThroughRoot = max(leftDiameter, rightDiameter);
        
        return max(pathThroughRoot, pathNotThroughRoot);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        return diameter(root) - 1;
        
    }
};