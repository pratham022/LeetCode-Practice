class Solution {
public:
    int findPivotIndex(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > nums[high]) {
                // array from low to mid is sorted, so pivot element will be in 
                // the other part
                low = mid + 1;
            }
            else 
                high = mid;
        }
        return low;
    }
    
    int binarySearch(vector<int> &nums, int low, int high, int target) {
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        // Approach: 1. First find the pivot element in the array
        // Pivot element is the element with minimum value
        // 2. Then elements to the left of pivot will be sorted 
        // 3. Also elements to the right of pivot will be sorted
        // 4. Then apply binary search on these two parts separately
        
        int indexPivot = findPivotIndex(nums);
        
        int indexInLeftArr = binarySearch(nums, 0, indexPivot-1, target);
        if(indexInLeftArr != -1)
            return indexInLeftArr;
        
        int indexInRightArr = binarySearch(nums, indexPivot, nums.size()-1, target);
        if(indexInRightArr != -1)
            return indexInRightArr;
        
        return -1;
        
    }
};