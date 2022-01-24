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
    TreeNode* helper(vector<int> &preorder, int &ind, int low, int high) {
        if(ind >= preorder.size() || low > high) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[ind]);
        ind++;
        
        int i;
        for(i=low; i <= high; i++) {
            if(preorder[i] > root->val)
                break;
        }
        
        root->left = helper(preorder, ind, ind, i-1);
        root->right = helper(preorder, ind, i, high);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        // O(N square approach)
        // https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
        
        // The first element of preorder traversal is always root. 
        // We first construct the root. 
        // Then we find the index of the first element which is greater than the root.
        // Let the index be ‘i’. The values between root and ‘i’ will be part of the
        // left subtree, and the values between ‘i'(inclusive) and ‘n-1’ will be part
        // of the right subtree. 
        // Divide given pre[] at index “i” and recur for left and right sub-trees. 
        
        int ind = 0;
        int n = preorder.size();
        return helper(preorder, ind, 0, n-1);
        
    }
};