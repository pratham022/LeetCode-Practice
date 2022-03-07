// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {
        
        vector<vector<long long int>> dp(m+1, vector<long long int>(n+1, 0));
        
        for(int j=0; j<=n; j++)
            dp[0][j] = 0;
        for(int i=0; i<=m; i++)
            dp[i][0] = 1;
        
        for(int i=1; i<=m; i++) {
            
            for(int j=1; j<=n; j++) {
                if(S[i-1] <= j) {
                    long long int included = dp[i][j - S[i-1]];
                    long long int notIncluded = dp[i-1][j];
                    
                    dp[i][j] = included + notIncluded;
                }
                else {
                    long long int notIncluded = dp[i-1][j];
                    dp[i][j] = notIncluded;
                }
                
            }
        }
        
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends