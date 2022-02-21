class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // good explanation: https://www.youtube.com/watch?v=quAS1iydq7U
        int n = nums.size();
        bool flag = false;
        
        for(int i=n-1; i>0; i--) {
            
            if(nums[i] > nums[i-1]) {
                i--;
                flag = true;
                int diff;
                int ansDiff = 1001;
                int ind = i;
                
                for(int j=i+1; j<n; j++) {
                    if(nums[j] > nums[i]) {
                        diff = nums[j] - nums[i];
                        if(diff <= ansDiff) {
                            ansDiff = diff;
                            ind = j;
                        }
                    }
                }
                
                swap(nums[i], nums[ind]);
                reverse(nums.begin()+i+1, nums.end());
                break;
            }
        }
        
        if(flag == false)
            reverse(nums.begin(), nums.end());
    }
};