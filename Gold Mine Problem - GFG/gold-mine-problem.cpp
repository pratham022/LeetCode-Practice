// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++)
            dp[i][0] = M[i][0];
        
        
        for(int j=1; j<m; j++) {
            for(int i=0; i<n; i++) {
                
                int fromRight = dp[i][j-1];
                int fromRightTop = 0;
                int fromRightBottom = 0;
                
                if(i-1 >= 0)
                    fromRightTop = dp[i-1][j-1];
                
                if(i+1 < n)
                    fromRightBottom = dp[i+1][j-1];
                    
                dp[i][j] = M[i][j] + max(
                    max(fromRight, fromRightTop), fromRightBottom
                );
                
            }
        }
        
        int res = 0;
        for(int i=0; i<n; i++) {
            res = max(res, dp[i][m-1]);
        }
        
        return res;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends