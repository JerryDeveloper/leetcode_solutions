class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3)
            return {};
        
        // sort to make sure unique
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() ; ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int start = i + 1;
            int end = nums.size() - 1;
            
            int target = 0 - nums[i];
            
            while(start < end)
            {
                int new_sum = nums[start] + nums[end];
                if(new_sum < target) ++start;
                else if(new_sum > target) --end;
                else
                {
                    int cur_start = nums[start];
                    int cur_end = nums[end];
                    res.push_back({nums[i], cur_start, cur_end});
                    
                    while(start < end && nums[start] == cur_start) ++start;
                    while(start < end && nums[end] == cur_end) --end;
                }
            }
        }
        
        return res;
    }
};