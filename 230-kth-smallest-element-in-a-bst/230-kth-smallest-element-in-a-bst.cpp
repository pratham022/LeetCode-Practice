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
    int kthSmallest(TreeNode* root, int k) {
        
        if(root == NULL)
            return -1;
        
        stack<TreeNode* > st;
        TreeNode* p = root;
        
        while(p != NULL) {
            st.push(p);
            p = p->left;
        }
        
        while(!st.empty()) {
            p = st.top();
            st.pop();
            
            k--;
            if(k == 0)
                return p->val;
            
            p = p->right;
            while(p) {
                st.push(p);
                p = p->left;
            }
        }
        
        return -1;
        
    }
};