class Solution {
public:
    void solve(int i, vector<int> &curr, int sum, vector<int>& candidates, 
                int target, vector<vector<int>> &res) {

        if(sum > target)
            return;
        else if(sum == target) {
            res.push_back(curr);
            return;
        }
        else {
            
            for(int j=i; j<candidates.size(); j++) {
                curr.push_back(candidates[j]);
                
                solve(j, curr, sum+candidates[j], candidates, target, res);
                
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        
        int sum = 0;
        vector<int> curr;
        
        solve(0, curr, 0, candidates, target, res);
        
        return res;
        
    }
};