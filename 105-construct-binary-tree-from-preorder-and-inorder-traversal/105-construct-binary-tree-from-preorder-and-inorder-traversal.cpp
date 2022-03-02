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
    unordered_map<int, int> inMap;
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, 
                        int &preInd) {
        
        if(start > end || preInd >= preorder.size())
            return NULL;
        
        int elem = preorder[preInd];
        int inorderInd = inMap[elem];
        
        preInd++;
        
        TreeNode* root = new TreeNode(elem);
        root->left = solve(preorder, inorder, start, inorderInd-1, preInd);
        root->right = solve(preorder, inorder, inorderInd+1, end, preInd);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0; i<inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        int preInd = 0;
        return solve(preorder, inorder, 0, inorder.size()-1, preInd);
        
        
    }
};