class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];
        
        int ans = nums[0];
        
        for(int i=1; i<n; i++) {
            
            int temp = maxEndingHere;
            maxEndingHere = max(nums[i], 
                                max(maxEndingHere*nums[i], minEndingHere*nums[i])
                            );
            
            minEndingHere = min(nums[i], 
                               min(minEndingHere*nums[i], temp*nums[i])
                            );
            
            ans = max(ans, maxEndingHere);
            
        }
        
        return ans;
        
    }
};