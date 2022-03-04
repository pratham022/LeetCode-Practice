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
                dfs(i, prevColor, graph, color, flag);
                if(flag == false)
                    return false;
            }
        }
        
        return true;
    }
};