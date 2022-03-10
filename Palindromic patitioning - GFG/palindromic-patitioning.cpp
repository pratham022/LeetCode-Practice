// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    bool isPalindrome(string s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string s, int i, int j) {
        if(i == j) {
            dp[i][j] = 0;
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(isPalindrome(s, i, j)) {
            dp[i][j] = 0;
            return 0;
        }
        
        int min = INT_MAX;
        for(int k=i; k<j; k++) {
            
            int temp = 1; 
            if(dp[i][k] == -1)
                temp += solve(s, i, k);
            else
                temp += dp[i][k];
                
            if(dp[k+1][j] == -1)
                temp += solve(s, k+1, j);
            else
                temp += dp[k+1][j];
            
            if(temp < min)
                min = temp;
        }
        dp[i][j] = min;
        return dp[i][j];
        
    }
    int palindromicPartition(string str)
    {
        // code here
        for(int i=0; i<501; i++) {
            for(int j=0; j<501; j++) 
                dp[i][j] = -1;
        }
        
        int n = str.length();
        return solve(str, 0, n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends