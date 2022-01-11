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
    void helper(TreeNode* root, int currNum, int &totalSum) {
        if(root == NULL)
            return;
        
        currNum = (currNum << 1) | root->val;
        if(root->left == NULL && root->right == NULL) {
            totalSum += currNum;
        }
        helper(root->left, currNum, totalSum);
        helper(root->right, currNum, totalSum);
    }
    int sumRootToLeaf(TreeNode* root) {
        
        
        // If you work with binaries 1 -> 1 -> 3, it's the same. 
        // You start from curr_number = 1, 
        // then shift one register to the left and add the next digit: 
        // curr_number = (1 << 1) | 1 = 3.
        int totalSum = 0;
        helper(root, 0, totalSum);
        return totalSum;
        
    }
};