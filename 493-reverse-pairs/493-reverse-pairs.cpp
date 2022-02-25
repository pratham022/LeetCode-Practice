class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {
        
        int i = low;
        int j = mid+1;
        
        int count = 0;
        
        while(i <= mid && j <= high) {
            
            if((long) nums[i] > (long) 2*nums[j]) {
                count += (mid - i + 1);
                j++;
            }
            else
                i++;
        }
        
        sort(nums.begin()+low, nums.begin()+high+1);
        return count;
    }
    int mergeSort(vector<int>& nums, int low, int high) {
        int count = 0;
        if(low < high) {
            int mid = (low + high) / 2;
            
            count += mergeSort(nums, low, mid);
            count += mergeSort(nums, mid+1, high);
            count += merge(nums, low, mid, high);
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        
        return mergeSort(nums, 0, n-1);
    }
};