class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int fresh = 0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        int time = -1;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        while(!q.empty()) {
            int sq = q.size();
            
            for(int i=0; i<sq; i++) {
                pair<int, int> curr = q.front();
                q.pop();
                
                for(int j=0; j<4; j++) {
                    int x = curr.first + dx[j];
                    int y = curr.second + dy[j];
                    
                    if(x >= 0 && x < m && y >= 0 && y < n) {
                        if(grid[x][y] == 1) {
                            grid[x][y] = 2;
                            q.push({x, y});
                            fresh--;
                        }
                    }
                }   
            }
            time++;
        }
        
        if(fresh > 0) return -1;
        if(time == -1) return 0;
        else return time;
        
    }
};