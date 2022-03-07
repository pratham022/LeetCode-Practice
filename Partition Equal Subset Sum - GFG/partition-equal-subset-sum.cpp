// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++)
            sum += arr[i];
        
        if(sum % 2 != 0)
            return 0;
        
        sum = sum / 2;
        
        // now, we have to find if there exists a subset with the half sum
        
        vector<vector<bool>> dp(N+1, vector<bool>(sum+1, false));
        
        for(int j=0; j<=sum; j++)
            dp[0][j] = false;
        for(int i=0; i<=N; i++)
            dp[i][0] = true;
        
        
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=sum; j++) {
                
                if(arr[i-1] <= j) {
                    // current element MAY be included OR MAY NOT be included
                    bool included = dp[i-1][j - arr[i-1]];
                    bool notIncluded = dp[i-1][j];
                    
                    dp[i][j] = included || notIncluded;
                }
                else {
                    // current element NOT allowed
                    bool notIncluded = dp[i-1][j];
                    dp[i][j] = notIncluded;
                }
                
            }
        }
        
        if(dp[N][sum] == true)
            return 1;
        else
            return 0;
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends