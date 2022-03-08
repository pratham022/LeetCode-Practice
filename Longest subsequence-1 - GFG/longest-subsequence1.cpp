// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int A[]) {
        
        vector<int> dp(n, 1);
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                
                int diff = abs(A[j] - A[i]);
                if(diff == 1) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int res = dp[0];
        for(int i=1; i<n; i++)
            res = max(res, dp[i]);
        return res;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends