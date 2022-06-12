class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        int i = 0, j = 0;
        int maxScore = 0, score = 0;
        
        while(j < n) {
            if(mp[nums[j]]) {
                while(mp[nums[j]]) {
                    mp[nums[i]]--;
                    score -= nums[i];
                    i++;
                }
            }
            else {
                mp[nums[j]]++;
                score += nums[j];
                maxScore = max(maxScore, score);
                j++;
            }

        }
        
        return maxScore;
    }
};