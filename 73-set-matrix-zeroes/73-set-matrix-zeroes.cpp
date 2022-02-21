class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // explanation video: https://www.youtube.com/watch?v=coOCVuBx7YA
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        
        bool row0 = false;
        bool col0 = false;
        // This is essential because while traversing the array, 0th row and 0th col
        // will be overrided with 0s based upon the other elements
        // So, we have to compute the result for 0th row and col at the beginning only
        
        for(int i=0; i<m; i++) {
            if(matrix[0][i] == 0)
                row0 = true;
        }
        
        for(int i=0; i<n; i++) {
            if(matrix[i][0] == 0)
                col0 = true;
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    
                    // using the 0th row and 0th col of matrix as indicators
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                
                // replacing matrix[i][j] with 0 based upon an of the indicators
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        // using booleans row0 and col0 to set 0th row and column
        if(row0) {
            for(int i=0; i<m; i++) {
                matrix[0][i] = 0;
            }
        }
        
        if(col0) {
            for(int i=0; i<n; i++) {
                matrix[i][0] = 0;
            }
        }
        
    }
};