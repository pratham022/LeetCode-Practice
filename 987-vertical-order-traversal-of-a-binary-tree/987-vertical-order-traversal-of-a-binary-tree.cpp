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
    void traverse(TreeNode* root, map<int, vector<pair<int, int>> > &mp, 
                    int row, int col) {
        
        if(root == NULL)
            return;
        
        pair<int, int> curr = make_pair(row, root->val);
        
        mp[col].push_back(curr);
        
        traverse(root->left, mp, row+1, col-1);
        traverse(root->right, mp, row+1, col+1);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map
        // col -> [ (row, node->val), (row, node->val), (row, node->val) ]
        
        map<int, vector<pair<int, int>> > mp;
        
        traverse(root, mp, 0, 0);
        
        for(auto x : mp) {
            int col = x.first;
            vector<pair<int, int>> arr = x.second;
            
            sort(arr.begin(), arr.end());
            
            mp[col] = arr;
        }
        
        vector<vector<int>> res;
        
        for(auto x : mp) {
            vector<pair<int, int>> curr = x.second;
            
            vector<int> temp;
            for(int i=0; i<curr.size(); i++) {
                pair<int, int> p = curr[i];
                temp.push_back(p.second);
            }
            
            res.push_back(temp);
        }
        
        return res;
        
    }
};