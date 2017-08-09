class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // only one pointer: the first zero
        int pt1 = 0;
        
        for(int pt2 = 0; pt2 < nums.size(); ++pt2)
        {
            if(nums[pt2] != 0)
            {
                nums[pt1] = nums[pt2];
                ++pt1;
            }
        }
        
        while(pt1 < nums.size())
            nums[pt1++] = 0;
    }
};