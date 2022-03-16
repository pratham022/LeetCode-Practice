// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool canColor(int node, bool graph[101][101], int color[], int col, int V) {
    
    for(int j=0; j<V; j++) {
        if(j != node && graph[node][j] == 1 && color[j] == col) {
            
            // there is an edge from i to j
            // color of j is already equal to col, so we cannot use this col
            return false;
        }
    }
    return true;
}

bool solve(int node, bool graph[101][101], int color[], int m, int V) {
    
    // we have colored all the vertices from 0 to V-1, so return true
    if(node == V)
        return true;
    
    // now, try to color the current vertex i will all the colors from 1 to m
    
    for(int j=1; j<=m; j++) {
        
        if(canColor(node, graph, color, j, V)) {
            color[node] = j;
            
            if(solve(node+1, graph, color, m, V))
                return true;
            
            color[node] = 0;
        }
        
    }
    return false;
    
    
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V] = {0};

    if(solve(0, graph, color, m, V))
        return true;
    else
        return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends