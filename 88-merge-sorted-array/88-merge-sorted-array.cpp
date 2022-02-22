class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i, j, k;
        i = m - 1;
        j = n - 1;
        k = m + n - 1;
        
        while(i >= 0 && j >= 0 && k >= i) {
            
            if(nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        
        // now replace the remaining elems from nums2 into nums1
        if(j >= 0) {
            
            i++;
            int l = 0;
            while(i <= k) {
                nums1[i] = nums2[l];
                i++;
                l++;
            }
            
        }
    }
};