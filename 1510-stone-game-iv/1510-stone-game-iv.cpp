class Solution {
public:
    bool winnerSquareGame(int n) {
        
        vector<bool> dp(n+1, false);
        dp[0] = false;
        dp[1] = true;
        
        for(int i=2; i<=n; i++) {
            
            for(int k=1; k*k <= i; k++) {
                
                int idx = i - (k * k);
                if(idx >= 0) {
                    if(dp[idx] == false) {
                        
                        // current player can force the other player to go on a 
                        // loosing index
                        // thus the current player wins!
                        dp[i] = true;
                        break;
                    }
                }
                else
                    break;
                
            }
        }
        
        return dp[n];
        
    }
};