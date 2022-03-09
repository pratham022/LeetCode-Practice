// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1005][1005];
    int solve(int arr[], int i, int j) {
        
        if(i == j) {
            dp[i][j] = 0;
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        for(int k=i; k<j; k++) {
            int tempAns = solve(arr, i, k) + 
                            solve(arr, k+1, j) + 
                            (arr[i-1] * arr[k] * arr[j]);
                            
            if(tempAns < ans)
                ans = tempAns;
        }
        dp[i][j] = ans;
        return dp[i][j];
        
    }
    int matrixMultiplication(int N, int arr[])
    {
        for(int i=0; i<1001; i++) {
            for(int j=0; j<1001; j++)
                dp[i][j] = -1;
        }
        return solve(arr, 1, N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends