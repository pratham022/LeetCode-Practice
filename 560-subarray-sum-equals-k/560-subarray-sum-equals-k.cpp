class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int, int> mp;
        
        int sum = 0;
        int cnt = 0;
        
        for(int x : nums) {
            sum += x;
            if(sum == k)
                cnt++;
            int requiredSum = sum - k;
            
            if(mp.find(requiredSum) != mp.end()) {
                cnt += mp[requiredSum];   
            }
            
            mp[sum]++;
        }
        
        return cnt;
    }
};