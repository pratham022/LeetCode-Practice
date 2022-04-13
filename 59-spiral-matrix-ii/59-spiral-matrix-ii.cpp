class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n, vector<int>(n));
        
        int curr = 1;
        int left = 0, right = n-1, top = 0, bottom = n-1;
        string dir = "right";
        
        while(left <= right && top <= bottom) {
            if(dir == "right") {
                for(int i=left; i<=right; i++) {
                    res[top][i] = curr;
                    curr++;
                }
                dir = "bottom";
                top++;
            }
            else if(dir == "bottom") {
                for(int i=top; i<=bottom; i++) {
                    res[i][right] = curr;
                    curr++;
                }
                dir = "left";
                right--;
            }
            else if(dir == "left") {
                for(int i=right; i>=left; i--) {
                    res[bottom][i] = curr;
                    curr++;
                }
                dir = "top";
                bottom--;
            }
            else if(dir == "top") {
                for(int i=bottom; i>=top; i--) {
                    res[i][left] = curr;
                    curr++;
                }
                dir = "right";
                left++;
            }
        }
        
        return res;
        
    }
};