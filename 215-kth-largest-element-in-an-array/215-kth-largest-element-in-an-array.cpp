class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue<int> pq;
        for(int i=0; i<n; i++)
            pq.push(nums[i]);
        
        int elem = INT_MIN;
        while(!pq.empty() && k--) {
            elem = pq.top();
            pq.pop();
        }
        
        return elem;
    }
};