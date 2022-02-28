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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        
        stack<TreeNode* > st;
        TreeNode* p = root;
        
        while(p != NULL) {
            res.push_back(p->val);
            st.push(p);
            p = p->left;
        }
        
        while(!st.empty()) {
            p = st.top();
            st.pop();
            
            p = p->right;
            while(p != NULL) {
                res.push_back(p->val);
                st.push(p);
                p = p->left;
            }
            
        }
        
        return res;
        
    }
};