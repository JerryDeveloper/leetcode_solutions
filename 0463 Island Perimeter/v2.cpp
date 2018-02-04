class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        // only need to count top and left (the bottom and right is another block's top and left, if they are neighboring)
        
        if(grid.size() == 0)
            return 0;
        
        int height = grid.size();
        int width = grid[0].size();
        int peri = 0;
        for(int i = 0; i < height; ++i)
        {
            for(int j = 0; j < width; ++j)
            {
                if(grid[i][j] == 1)
                {
                    peri += 4;
                
                    if(i > 0 && grid[i - 1][j] == 1) peri -= 2;
                    if(j > 0 && grid[i][j - 1] == 1) peri -= 2;
                }
            }
        }
        
        return peri;
    }
};