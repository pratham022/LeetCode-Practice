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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        stack<pair<TreeNode*, int>> st;
        
        TreeNode* p = root;
        while(p != NULL) {
            st.push(make_pair(p, 0));
            p = p->left;
        }
        
        while(!st.empty()) {
            
            pair<TreeNode*, int> curr = st.top();
            st.pop();
            p = curr.first;
            
            if(curr.second == 0) {
                // I am returning from left side of the tree...
                // so again push in the stack
                curr.second = 1;
                st.push(curr);
                
                // now go to the right subtree
                p = p->right;
                
                while(p != NULL) {
                    st.push(make_pair(p, 0));
                    p = p->left;
                }
                
            }
            else {
                // I am returning from the right side..
                res.push_back(p->val);
            }
        }
        
        return res;
        
    }
};