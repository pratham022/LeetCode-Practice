class Solution {
public:
    void dfs(int i, int j, int oldColor, int newColor, 
                    vector<vector<int>>& image) {
        
        image[i][j] = newColor;
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        for(int p=0; p<4; p++) {
            int x = i + dx[p];
            int y = j + dy[p];
            
            if(x >= 0 && x < image.size() 
                && y >= 0 && y < image[0].size() && image[x][y] == oldColor) {
                dfs(x, y, oldColor, newColor, image);   
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;
        dfs(sr, sc, image[sr][sc], color, image);
        return image;
    }
};