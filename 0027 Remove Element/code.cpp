class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last_index = -1;
        int count = 0;
        for(auto pt = nums.begin(); pt != nums.end(); ++pt)
        {
            if((*pt) != val)
            {
                nums[++last_index] = (*pt);
                ++count;
            }
        }
        
        return count;
    }
};