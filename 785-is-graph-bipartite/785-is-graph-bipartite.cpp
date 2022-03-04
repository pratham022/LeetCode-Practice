class Solution {
public:
    void dfs(int i, int prevColor, vector<vector<int>>& graph, 
                vector<int> &color, bool &flag) {
        
        if(flag == false) return;
        
        color[i] = prevColor ^ 1;
        
        for(int j=0; j<graph[i].size(); j++) {
            int neighbor = graph[i][j];
            
            if(color[neighbor] == -1) {
                // neighbor is not yet visited, so start dfs
                dfs(neighbor, color[i], graph, color, flag);
            }
            else {
                // check neighbor's color
                if(color[neighbor] == color[i]) {
                    // INVALID
                    flag = false;
                    return;
                }
            }
        }
        
    }
    void bfs(int i, vector<vector<int>> &graph, vector<int> &color, bool &flag) {
        
        queue<int> q;
        q.push(i);
        color[i] = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int j=0; j<graph[node].size(); j++) {
                int neighbor = graph[node][j];
                
                if(color[neighbor] == -1) {
                    color[neighbor] = color[node] ^ 1;
                    q.push(neighbor);
                }
                else {
                    if(color[neighbor] == color[node]) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        // color[i] = -1 => not visited
        // color[i] = 0 => red color
        // color[i] = 1 => blue color
        vector<int> color(n, -1);
        
        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                // start coloring
                bool flag = true;
                int prevColor = 1;
                // dfs(i, prevColor, graph, color, flag);
                bfs(i, graph, color, flag);
                if(flag == false)
                    return false;
            }
        }
        
        return true;
    }
};