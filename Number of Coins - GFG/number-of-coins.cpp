// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
        int n = M;
        int amount = V;
        
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=amount; j++) {
                
                if(j == 0)
                    dp[i][j] = 0;
                else if(i == 0)
                    dp[i][j] = INT_MAX - 1;
                else if(coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                }
            }
        }
        
        if(dp[n][amount] == INT_MAX - 1)
            return -1;
        else
            return dp[n][amount];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends