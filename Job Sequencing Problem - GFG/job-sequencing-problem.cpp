// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comparator(Job a, Job b) {
        if(a.profit > b.profit)
            return true;
        else
            return false;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, comparator);
        
        // find the maximum deadline from array
        int maxDeadline = arr[0].dead;
        for(int i=1; i<n; i++)
            maxDeadline = max(maxDeadline, arr[i].dead);
        
        bool slots[maxDeadline + 1];
        
        // initialise all slots as empty
        for(int i=0; i<=maxDeadline; i++)
            slots[i] = false;
        
        int maxProfit = 0;
        int jobs = 0;
        
        for(int i=0; i<n; i++) {
            
            // find a free slot for this job 
            for(int j=arr[i].dead; j>0; j--) {
                
                if(slots[j] == false) {
                    slots[j] = true;
                    jobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
                
            }
            
        }
        
        return {jobs, maxProfit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends