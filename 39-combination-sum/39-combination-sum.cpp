class Solution {
public:
    void helper(vector<int>& candidates, int target, 
                    vector<vector<int>> &res, vector<int> &curr, int &sum, int ind) {
        
        if(sum > target)
            return;
        
        if(sum == target) {
            res.push_back(curr);
            return;
        }
        
        for(int i=ind; i<candidates.size(); i++) {
            sum += candidates[i];
            curr.push_back(candidates[i]);
            
            helper(candidates, target, res, curr, sum, i);
            
            sum -= candidates[i];
            curr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> curr;
        int sum = 0;
        
        helper(candidates, target, res, curr, sum, 0);
        
        return res;
    }
};