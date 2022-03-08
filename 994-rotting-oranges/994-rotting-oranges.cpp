class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int fresh = 0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1)
                    fresh++;
                if(grid[i][j] == 2) 
                    q.push({i, j});
            }
        }
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int mins = -1;
        while(!q.empty()) {
            int sq = q.size();
            for(int i=0; i<sq; i++) {
                
                pair<int, int> p = q.front();
                q.pop();
                
                for(int j=0; j<4; j++) {
                    
                    int x = p.first + dx[j];
                    int y = p.second + dy[j];
                    
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                    }
                }
            }
            mins++;
        }
        
        if(fresh > 0) return -1;
        if(mins == -1) return 0;
        else return mins;
        
    }
};