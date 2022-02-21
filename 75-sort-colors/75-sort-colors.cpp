class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        // start points to the last index where 0 will be present
        // end points to the first index where 2 will be present
        int start = 0;
        int end = n-1;
        
        int i = 0;
        while(i <= end) {
            if(nums[i] == 0) {
                swap(nums[i], nums[start]);
                start++;
                i++;
            }
            else if(nums[i] == 2) {
                swap(nums[i], nums[end]);
                end--;
            }
            else 
                i++;
        }
    }
};