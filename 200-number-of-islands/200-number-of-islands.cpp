class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid) {
        
        grid[i][j] = '0';
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        for(int p=0; p<4; p++) {
            
            int x = i + dx[p];
            int y = j + dy[p];
            
            if(x >= 0 && x < m && y >= 0 && y < n) {
                // visit the next adj vertex
                
                if(grid[x][y] == '1')
                    dfs(x, y, m, n, grid);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int islands = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                if(grid[i][j] == '1') {
                    dfs(i, j, m, n, grid);
                    islands++;
                }
            }
        }
        
        return islands;
        
    }
};