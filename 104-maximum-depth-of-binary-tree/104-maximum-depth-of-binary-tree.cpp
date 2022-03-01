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
    void findMaxDepth(TreeNode* root, int currDepth, int &depth) {
        
        if(root == NULL) {
            depth = max(depth, currDepth);
            return;
        }
        findMaxDepth(root->left, currDepth+1, depth);
        findMaxDepth(root->right, currDepth+1, depth);
        
    }
    int maxDepth(TreeNode* root) {
        
        int depth = 0;
        
        if(root == NULL)
            return depth;
        
        findMaxDepth(root, 0, depth);
        return depth;
    }
};