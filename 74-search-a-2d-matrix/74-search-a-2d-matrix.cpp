class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i;
        for(i=0; i<m; i++) {
            int low = 0;
            int high = n-1;
            
            if(target > matrix[i][high]) {
                // target does not lie in this row
            }
            else if(target < matrix[i][low]) {
                // target does not lie in this row
                // but definetly it will not lie in any other row
                return false;
            }
            else {
                vector<int>::iterator it;
                it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
                
                if(it == matrix[i].end())
                    return false;
                else {
                    int idx = it - matrix[i].begin();
                    
                    if(matrix[i][idx] == target)
                        return true;
                    else
                        return false;
                }
            }
        }
        return false;
    }
};