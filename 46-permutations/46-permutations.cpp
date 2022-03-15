class Solution {
public:
    void backtrack(vector<int>& nums, int l, int r, vector<vector<int>> &res) {
        
        if(l == r) {
            res.push_back(nums);
            return;
        }
        
        for(int i=l; i<=r; i++) {
            
            swap(nums[l], nums[i]);
            
            backtrack(nums, l+1, r, res);
            
            swap(nums[l], nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        backtrack(nums, 0, nums.size()-1, res);
        
        return res;
    }
};