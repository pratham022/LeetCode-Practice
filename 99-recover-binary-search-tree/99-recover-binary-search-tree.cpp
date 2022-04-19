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
    void inorder(TreeNode* root, TreeNode* &prev, 
                        TreeNode* &first, TreeNode* &second) {
        if(root == NULL)
            return;
        
        inorder(root->left, prev, first, second);
        
        // check here
        if(prev != NULL) {
            if(prev->val > root->val) {
                // check if this is the first pair or not?
                if(first == NULL)
                    first = prev;
                
                // to handle the corner case of only 1 pair
                second = root;
            }
        }
        
        prev = root;
        inorder(root->right, prev, first, second);
    }
    void recoverTree(TreeNode* root) {
        // https://www.youtube.com/watch?v=LR3K5XAWV5k
        // There will be generally two pairs of elements where the previous element 
        // will be greater than current
        
        // We have to swap the first element of first pair 
        // with second element of last pair
        // This approach fails in the case when we have only 1 pair present
        
        // inorder array of BST is always increasing (Left, Visit, Right)
        // [3, 2, 1] => two pairs where inorder[i] > inorder[i+1]
        // [1, 2, 3]

        // [1, 3, 2, 4] => corner case when only 
                            // one pair where inorder[i] > inorder[i+1]
        
        
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        inorder(root, prev, first, second);
        
        swap(first->val, second->val);
    }
};