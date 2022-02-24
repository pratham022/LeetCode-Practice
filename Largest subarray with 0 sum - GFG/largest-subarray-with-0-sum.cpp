// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int ansLen = 0;
        
        unordered_map<int, int> mp;
        int sum = 0;
        
        for(int i=0; i<n; i++) {
            
            sum += A[i];
            
            if(sum == 0) {
                // corner test case: [1, -1, 1, -1]
                // if we do not consider sum = 0 case, our output will go wrong 
                // test this and you will know where it goes wrong
                ansLen = i + 1;
            }
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
            else {
                // sum is repeated, so we found a subarray with 0 sum
                ansLen = max(ansLen, i - mp[sum]);
            }
        }
        
        return ansLen;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends