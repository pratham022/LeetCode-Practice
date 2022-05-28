class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int missingNum = nums[0];
        for(int i=1; i<n; i++)
            missingNum ^= nums[i];
        
        for(int i=1; i<=n; i++)
            missingNum ^= i;
        
        return missingNum;
        
    }
};