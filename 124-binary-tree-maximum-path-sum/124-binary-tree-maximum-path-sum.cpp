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
    int solve(TreeNode* root, int &maxSum) {
        
        if(root == NULL)
            return 0;
        
        int l = solve(root->left, maxSum);
        int r = solve(root->right, maxSum);
        
        int temp = max(max(l,r)+root->val,root->val);
        int ans = max(temp, l+r+root->val);
        maxSum = max(ans, maxSum);
        
        return temp;
        
    }
    int maxPathSum(TreeNode* root) {
        // 3 cases
        // max path passes upwards from either left / right
        // max path passes downwards from the root
        // do not include anything...just pass root's val upwards
        
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};