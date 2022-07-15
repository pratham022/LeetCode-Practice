class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int &area) {
        grid[i][j] = 0;
        area++;
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        for(int p=0; p<4; p++) {
            int x = i + dx[p];
            int y = j + dy[p];
            
            if(x >= 0 && x < n && y >= 0 && y < m) {
                if(grid[x][y] == 1)
                    dfs(x, y, n, m, grid, area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, n, m, grid, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
        
    }
};