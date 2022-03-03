class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int total = 0;
        
        int n = nums.size();
        
        for(int i=0; i<=n-3; i++) {
            // i will be starting point
            int j = i+1;
            
            int diff = nums[j] - nums[i];
            int multiple = 1;
            
            for(int k=j+1; k<n; k++) {
                if(nums[k] - nums[j] == multiple*diff) {
                    total++;
                    multiple++;
                }
                else
                    break;
            }
        }
        return total;
    }
};