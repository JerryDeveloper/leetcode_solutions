class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() == 0 || nums[0].size() == 0)
            return nums;
        
        int ori_r = nums.size();
        int ori_c = nums[0].size();
        
        // cannot reshape
        if(ori_r * ori_c != r * c)
            return nums;
        
        vector<vector<int>> res(r);
        for(int i = 0; i < r; ++i)
        {
            vector<int> row(c);
            
            for(int j = 0; j < c; ++j)
            {
                int plain_index = i * c + j;
                int oi = plain_index / ori_c;
                int oj = plain_index % ori_c;
                
                row[j] = nums[oi][oj];
            }
            
            res[i] = row;
        }
        
        return res;
    }
};