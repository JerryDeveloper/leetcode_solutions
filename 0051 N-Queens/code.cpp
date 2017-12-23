class Solution {
public:
    
    // i is row, j is column
    bool isSafe(vector<string> board, int i, int j, const int n) {
        for(int k = 0; k < i; ++k)
            if(board[k][j] == 'Q')
                return false;
        
        // diagonal
        for(int p = max(i - j, 0), q = max(j - i, 0); p < i && q < j; ++p, ++q) 
            if(board[p][q] == 'Q')
                return false;
        
        // diagonal
        for(int p = i - 1, q = j + 1; p >= 0 && q < n; --p, ++q)
            if(board[p][q] == 'Q')
                return false;
        
        return true;
    }
    
    void solveNQueensUtil(vector<string> curBoard, int curRow, int curCol, const int n, vector<vector<string>> &res) {
        if(curRow == n)
            return;
        
        if(!isSafe(curBoard, curRow, curCol, n))
            return;
        
        curBoard[curRow][curCol] = 'Q';
        
        if(curRow == n - 1)
        {
            res.push_back(curBoard);
            return;
        }
        
        for(int i = 0; i < n; ++i)
        {
            if(i == curCol - 1 || i == curCol || i == curCol + 1)
                continue;
            
            solveNQueensUtil(curBoard, curRow + 1, i, n, res);
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        for(int i = 0; i < n; ++i)
        {
            vector<string> board(n, string(n, '.'));
            solveNQueensUtil(board, 0, i, n, res);
        }
        
        return res;
    }
};