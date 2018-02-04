class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res = {};
        
        if(numRows == 0)
            return res;
        
        vector<int> first_row = {1};
        res.push_back(first_row);
        
        for(int i = 1; i < numRows; ++i)
        {
            vector<int> prev_row = res[i - 1];
            vector<int> row(i + 1);
            row[0] = 1;
            row[i] = 1;
            for(int j = 1; j < i; ++j)
                row[j] = prev_row[j - 1] + prev_row[j];
            res.push_back(row);
        }
        
        return res;
    }
};