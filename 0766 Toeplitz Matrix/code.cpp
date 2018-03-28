ass Solution {
public:
    // traverse right each element from first row
    // then traverse down each element from first column
    
    bool diagonalIsSame(const vector<vector<int>>& matrix, int startRow, int startCol) {
        int m = startRow + 1;
        int n = startCol + 1;
        while(m < matrix.size() && n < matrix[m].size()) {
            if(matrix[m - 1][n - 1] != matrix[m][n])
                return false;

            ++m;
            ++n;
        }
        
        return true;
    }
    
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        if(matrix.size() == 0)
            return true;
        
        // traverse first row
        for(int ci = 0; ci < matrix[0].size(); ++ci) {
            if(!diagonalIsSame(matrix, 0, ci))
                return false;
        }
        
        // traverse first column
        for(int ri = 1; ri < matrix.size(); ++ri) {
            if(!diagonalIsSame(matrix, ri, 0))
                return false;
        }
        
        return true;
    }
};
