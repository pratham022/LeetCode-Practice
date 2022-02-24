class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++) {
            
            int x = nums[i];
            int required = target - x;
            
            if(mp.find(required) != mp.end())
                return {i, mp[required]};
            
            mp[x] = i;
        }
        
        return {-1, -1};
    }
};