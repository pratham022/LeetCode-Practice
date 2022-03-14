class Solution {
public:
    void solve(int i, int sum, vector<int> &curr, 
                        vector<int>& candidates, int target, set<vector<int>> &res) {
        
        if(sum > target)
            return;
        if(sum == target) {
            sort(curr.begin(), curr.end());
            res.insert(curr);
            return;
        }
        
        for(int j=i; j<candidates.size(); j++) {
            
            if(j && candidates[j] == candidates[j-1] && j > i) 
                continue;
            curr.push_back(candidates[j]);
            solve(j+1, sum+candidates[j], curr, candidates, target, res);
            curr.pop_back();
            
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        set<vector<int>> res;
        
        vector<int> curr;
        int sum = 0;
        solve(0, sum, curr, candidates, target, res);
        
        
        vector<vector<int>> ans;
        for(auto arr : res)
            ans.push_back(arr);
        
        return ans;
    }
};