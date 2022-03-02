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
    bool checkSymmetry(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL || q == NULL)
            return false;
        else {
            if(p->val != q->val)
                return false;
            else {
                bool a1 = checkSymmetry(p->left, q->right);
                bool a2 = checkSymmetry(p->right, q->left);
                
                return a1 && a2;
            }
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return checkSymmetry(root->left, root->right);
    }
};