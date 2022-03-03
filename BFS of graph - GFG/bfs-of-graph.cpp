// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int N, vector<int> g[]) {
        
        queue<int> q;
        vector<int> visited(N, 0);
        vector<int> ans;
        q.push(0);
        
        int curr;
        while(!q.empty()) {
            curr = q.front();
            
            if(visited[curr] == 0)
                ans.push_back(curr);
                
            visited[curr] = 1;
            q.pop();
            for(int i=0;i<g[curr].size();i++) {
                if(visited[g[curr][i]] == 0) {
                    q.push(g[curr][i]);
                }
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends