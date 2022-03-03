// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    void dfs(int i, int V, vector<int> adj[], vector<bool> &visited,
                vector<int> &res) {
        
        res.push_back(i);
        visited[i] = true;
        
        for(int j=0; j<adj[i].size(); j++) {
            int neighbor = adj[i][j];
            if(visited[neighbor] == false)
                dfs(neighbor, V, adj, visited, res);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> res;
        
        vector<bool> visited(V+1, false);
        
        dfs(0, V, adj, visited, res);
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends