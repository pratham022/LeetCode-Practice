class Solution {
public:
    vector<vector<string>> res;
    
    bool isValid(vector<string> &board, int row, int col) {
        
        // we are moving from left to right
        
        // check for row on left side
        for(int i=0; i<col; i++) {
            if(board[row][i] == 'Q')
                return false;
        }
        
        // Check for upper diagonal on left side
        for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }
        
        // Check for lower diagonal on left side
        for(int i=row, j=col; i<board.size() && j>=0; i++, j--) {
            if(board[i][j] == 'Q')
                return false;
        }
        
        return true;
        
    }
    void helper(vector<string> &board, int col) {
        
        if(col == board[0].size()) {
            res.push_back(board);
            return;
        }
        
        // check for every row
        for(int i=0; i<board.size(); i++) {
            
            if(isValid(board, i, col)) {
                
                board[i][col] = 'Q';
                
                helper(board, col+1);
                
                board[i][col] = '.';
                
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        if(n <= 0)
            return res;
        
        // n x n board
        vector<string> board(n, string(n, '.'));
        
        helper(board, 0);
        
        return res;
    }
};