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
class Info {
    
public:
    // minimum value in the subtree
    int mini;
    
    // maximum value in the subtree
    int maxi;
    
    // is the subtree a BST
    bool isBst;
    
    // subtree sum
    int sum;
    
    Info() {
        mini = 0;
        maxi = 0;
        isBst = true;
        sum = 0;
    }
    Info(int mini, int maxi, bool isBst, int sum) {
        this->mini = mini;
        this->maxi = maxi;
        this->isBst = isBst;
        this->sum = sum;
    }
};
class Solution {
public:
    Info* traverse(TreeNode* root, int &currMax) {
        
        if(root == NULL)
            return new Info(INT_MAX, INT_MIN, true, 0);
        
        if(root->left == NULL && root->right == NULL) {
            // leaf node
            currMax = max(currMax, root->val);
            return new Info(root->val, root->val, true, root->val);
        }
        
        Info* l = traverse(root->left, currMax);
        Info* r = traverse(root->right, currMax);
        
        Info* t = new Info();
        
        if(l->isBst && r->isBst && root->val > l->maxi && root->val < r->mini) {
            t->isBst = true;
            t->mini = min(root->val, min(l->mini, r->mini));
            t->maxi = max(root->val, max(l->maxi, r->maxi));
            t->sum = l->sum + root->val + r->sum;
            
            currMax = max(currMax, t->sum);
        }
        else {
            t->isBst = false;
        }
        
        return t;
    }
    int maxSumBST(TreeNode* root) {
        int currMax = 0;
        traverse(root, currMax);
        return currMax;
    }
};