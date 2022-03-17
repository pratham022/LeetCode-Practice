class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        // 1. boundary checks
        // size 1 array
        if(nums.size() == 1)
            return nums[0];
        
        // 1st element is unique
        if(nums[0] != nums[1])
            return nums[0];
        
        // last element unique
        if(nums[n-1] != nums[n-2])
            return nums[n-1];
        
        // lets say, we find the unique element on index idx
        // If we carefully observe the left and right subarrays, then
        // 1. Every pair on left part will start on even index and end at odd index
        // (even, odd) index
        
        // 2. Every pair on right part will start on odd index and end at even
        // (odd, even) index
        
        int low = 0, high = n - 1;
        int mid;
        
        while(low < high) {
            
            mid = low + (high - low) / 2;
            
            // unique elem will not be equal to any of it's neighbors
            if(nums[mid] == nums[mid-1]) {
                
                if(mid % 2 == 0) {
                    // pair starts on odd index...this is the property of right part
                    // So, we are standing in the right part wrt pivot 
                    // Thus, GO LEFT
                    high = mid - 2;
                }
                else
                    low = mid + 1;
                
            }
            else if(nums[mid] == nums[mid+1]) {
                if((mid+1) % 2 == 0) {
                    // pair starts on odd index...this is the property of right part
                    // So, we are standing in the right part wrt pivot 
                    // Thus, GO LEFT
                    high = mid - 1;
                }
                else
                    low = mid + 2;
                
            } 
            else {
                // if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1])
                return nums[mid];
            }
        }
        
        return nums[low];
        
        
    }
};