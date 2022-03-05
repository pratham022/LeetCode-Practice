// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<int> parent(n+1, -1);
        vector<int> key(n+1, INT_MAX);
        vector<bool> mstSet(n+1, false);
        
        key[0] = 0;
        parent[0] = -1;
        int cost = 0;
        
        for(int count=0; count<n-1; count++) {
            
            int mini = INT_MAX;
            int u;
            
            for(int i=0; i<n; i++) {
                if(mstSet[i] == false && key[i] < mini) {
                    mini = key[i];
                    u = i;
                }
            }
            
            mstSet[u] = true;
            
            for(int j=0; j<adj[u].size(); j++) {
                int v = adj[u][j][0];
                int weight = adj[u][j][1];
                
                if(mstSet[v] == false && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
            
        }
        
        for(int i=0; i<n; i++) {
            cost += key[i];
        }
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends