class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++) {
            if(!dq.empty() && dq.front() == i - k)  // removing out of bound indices
                dq.pop_front();
            
            // smaller elements will not contribute to anything, so pop them
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            // now push current index
            dq.push_back(i);
            
            // max element will be the front element of the deque
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};