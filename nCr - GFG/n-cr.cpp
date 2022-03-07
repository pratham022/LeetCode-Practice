// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // nCr = (n-1)C(r-1) + (n-1)Cr
        
        int MOD = 1000000007;
        if(n < r)
            return 0;
        vector<vector<int>> dp(n+1, vector<int>(r+1, 1));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=r; j++) {
                
                if(j <= i && j != i)
                    dp[i][j] = ((dp[i-1][j-1])%MOD + (dp[i-1][j])%MOD)%MOD;
                
            }
        }
        
        return dp[n][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends