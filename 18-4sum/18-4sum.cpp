class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        set<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                
                int currSum = nums[i] + nums[j];
                int reqSum = target - currSum;
                
                int low = j+1;
                int high = n-1;
                
                while(low < high) {
                    int sum = nums[low] + nums[high];
                    if(sum == reqSum) {
                        vector<int> temp = {nums[i], nums[j], nums[low], nums[high]};
                        sort(temp.begin(), temp.end());
                        res.insert(temp);
                        low++;
                        high--;
                    }
                    else if(sum < reqSum)
                        low++;
                    else
                        high--;
                }
            }
        }
        
        vector<vector<int>> ans;
        for(auto arr : res)
            ans.push_back(arr);
        return ans;
        
    }
};