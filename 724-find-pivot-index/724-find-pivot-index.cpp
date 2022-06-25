class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sum(n, 0);
        sum[0] = nums[0];
        for(int i=1; i<n; i++)
            sum[i] = sum[i-1] + nums[i];
        
        for(int i=0; i<n; i++) {
            int lSum = 0, rSum = 0;
            if(i > 0)
                lSum = sum[i-1];
            
            rSum = sum[n-1] - sum[i];
            
            if(lSum == rSum)
                return i;
        }
        return -1;
    }
};