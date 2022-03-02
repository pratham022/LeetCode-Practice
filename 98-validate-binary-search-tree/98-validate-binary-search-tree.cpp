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
    bool checkValid(TreeNode* root, long low, long high) {
        if(root == NULL)
            return true;
        
        if(root->val > low && root->val < high) {
            // current value of the node is valid because it lies in the range
            return checkValid(root->left, low, root->val) &&
                    checkValid(root->right, root->val, high);
        }
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {
        
        long low = LONG_MIN;
        long high = LONG_MAX;
        
        return checkValid(root, low, high);
    }
};