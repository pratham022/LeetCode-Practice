class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int> &curr, 
                    set<vector<int>> &ans) {
        
        if(i == nums.size()) {
            sort(curr.begin(), curr.end());
            ans.insert(curr);
            return;
        }
        
        curr.push_back(nums[i]);
        solve(i+1, nums, curr, ans);
        
        curr.pop_back();
        solve(i+1, nums, curr, ans);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>> ans;
        
        vector<int> curr;
        sort(nums.begin(), nums.end());
        
        solve(0, nums, curr, ans);
        
        vector<vector<int>> res;
        for(auto arr: ans) {
            res.push_back(arr);
        }
        return res;
        
    }
};