class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        map<int, int> mp;
        
        for(int x : nums)
            mp[x]++;
        
        int ansLen = 0;
        
        int len = 0;
        int prevNum = -1000000007;
        
        for(auto x : mp) {
            int ele = x.first;
            int freq = x.second;
            
            if(prevNum + 1 == ele) {
                // we can continue the previous sequence
                len++;
            }
            else {
                ansLen = max(ansLen, len);
                len = 1;
            }
            
            prevNum = ele;
        }
        
        ansLen = max(ansLen, len);
        
        return ansLen;
    }
};