class Solution {
public:
    int helper(vector<vector<int>>& costs, int i, int aRemain, int bRemain, 
                vector<vector<int>> &dp) {
        if(i == costs.size())
            return 0;
        
        if(dp[aRemain][bRemain] != INT_MAX)
            return dp[aRemain][bRemain];
        
        int minVal = INT_MAX;
        
        if(aRemain)
            minVal = costs[i][0] + helper(costs, i+1, aRemain-1, bRemain, dp);
        
        if(bRemain)
            minVal = min(minVal, 
                            costs[i][1] + helper(costs, i+1, aRemain, bRemain-1, dp));
        
        dp[aRemain][bRemain] = minVal;
        return dp[aRemain][bRemain];
        
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return helper(costs, 0, n/2, n/2, dp);
    }
};