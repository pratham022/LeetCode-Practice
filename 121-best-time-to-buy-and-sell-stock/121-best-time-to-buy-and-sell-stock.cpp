class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int minCost = prices[0];
        int maxProfit = 0;
        
        for(int i=1; i<n; i++) {
            minCost = min(minCost, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minCost);
        }
        
        return maxProfit;
        
    }
};