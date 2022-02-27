class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        
        int maxLen = 0;
        int prevLen = 0;
        int n = nums.length;
        
        for(int i=0; i<n; i++) {
            
            if(nums[i] == 1) {
                // we can either start new subarray at i or extend the previous
                
                if(i == 0 || prevLen == 0) {
                    // start a new subarray
                    prevLen = 1;
                }
                else {
                    // extend the previous subarray
                    prevLen++;
                }
            }
            else {
                maxLen = Math.max(maxLen, prevLen);
                prevLen = 0;
            }
        }
        maxLen = Math.max(maxLen, prevLen);
        return maxLen;
        
    }
}