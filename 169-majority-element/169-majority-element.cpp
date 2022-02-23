class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int majElem = nums[0];
        int cnt = 1;
        
        for(int i=1; i<n; i++) {
            if(nums[i] == majElem) {
                cnt++;
            }
            else {
                cnt--;
                if(cnt == 0) {
                    majElem = nums[i];
                    cnt = 1;
                }
            }
        }
        
        int actualCnt = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == majElem)
                actualCnt++;
        }
        
        if(actualCnt > (n/2))
            return majElem;
        else
            return -1;
        
    }
};