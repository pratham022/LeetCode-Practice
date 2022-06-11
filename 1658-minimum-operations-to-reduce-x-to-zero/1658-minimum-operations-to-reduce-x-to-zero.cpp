class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += nums[i];
        
        sum -= x;

        int i = 0;
        int curr = 0;
        int maxLen = 0;
        bool found = false;
        
        for(int j=0; j<n; j++) {
            curr += nums[j];
            
            while(i <= j && curr > sum) {
                curr -= nums[i];
                i++;
            }
            
            if(curr == sum) {
                found = true;
                maxLen = max(maxLen, j-i+1);
            }
        }
        
        if(found)
            return n - maxLen;
        else
            return -1;
    }
};