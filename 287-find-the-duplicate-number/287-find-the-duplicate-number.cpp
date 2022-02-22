class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int fast = nums[0];
        int slow = nums[0];
        
        // find if cycle exists
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while(fast != slow);
        
        // detect the starting point of the cycle
        fast = nums[0];
        while(fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        } 
        
        return slow;
    }
};