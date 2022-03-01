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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode* > q;
        q.push(root);
        bool revFlag = false;
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> curr(n);
            
            for(int i=0; i<n; i++) {
                TreeNode* p = q.front();
                q.pop();
                
                int idx = i;
                if(revFlag)
                    idx = n-i-1;
                curr[idx] = p->val;
                
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            
            res.push_back(curr);
            revFlag = !revFlag;
        }
        
        return res;
        
    }
};