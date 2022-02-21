class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int curr = nums[0];
        int ans = nums[0];
        
        for(int i=1; i<n; i++) {
            
            // if curr + nums[i] > nums[i], this means that we can continue the
            // previous subarray (subarray ending at i-1)
            
            // else, we have to start a new subarray from index i. In this case
            // we update curr = nums[i];
            if(curr + nums[i] > nums[i])
                curr = curr + nums[i];
            else
                curr = nums[i];
            
            // update the final answer
            ans = max(ans, curr);
        }
        
        return ans;
    }
};