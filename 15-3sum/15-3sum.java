class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
        int n = nums.length;
        Arrays.sort(nums);
        
        List<List<Integer>> res = new ArrayList<>();
        
        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i+1;
            int k = n-1;
            int target = 0 - nums[i];
            
            while(j < k) {
                
                if(nums[j] + nums[k] == target) {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    while(j < k && nums[j] == nums[j+1])
                        j++;
                    while(j < k && nums[k] == nums[k-1])
                        k--;
                    j++;
                    k--;
                }   
                else if(nums[j] + nums[k] < target)
                    j++;
                else
                    k--;
            }
        }
        
        return res;
        
    }
}