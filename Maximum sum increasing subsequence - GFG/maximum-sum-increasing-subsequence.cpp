// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n) {
	    
	    vector<int> dp(n, 0);
	    
	    for(int i=0; i<n; i++) {
	        dp[i] = arr[i];
	        for(int j=0; j<i; j++) {
	            
	            if(arr[i] > arr[j]) {
	                
	                // we can include arr[i] in the subseq ending at j
	                // 2 choices: include / not include
	                
	                if(dp[j] + arr[i] > dp[i])
	                    dp[i] = dp[j] + arr[i];
	            }
	        }
	    }
	    
	    int maxSum = dp[0];
	    for(int i=1; i<n; i++)
	        maxSum = max(maxSum, dp[i]);
	   
	    return maxSum;
	    
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends