class Solution {
public:
    void bfs(int i, int j, int m, int n, vector<vector<char>>& grid) {
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        
        while(!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            
            i = curr.first;
            j = curr.second;
            
            for(int p=0; p<4; p++) {
                
                int x = i + dx[p];
                int y = j + dy[p];
                
                if(x >= 0 && x < m && y >= 0 && y < n) {
                    
                    if(grid[x][y] == '1') {
                        q.push({x, y});
                        grid[x][y] = '0';
                    }
                }
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
                    bfs(i, j, m, n, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};