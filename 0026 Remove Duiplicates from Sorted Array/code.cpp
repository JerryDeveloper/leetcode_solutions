class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.empty())
            return 0;
        
        int res = 1;
        int last_index = 0;
        
        for(auto pt = nums.begin() + 1; pt != nums.end(); ++pt)
        {
            if((*pt) != nums[last_index]) 
            {
                ++res;
                nums[++last_index] = *pt;
            }
        }
        
        return res;
    }
};