class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // idea 1: sort the array first, then compare the newly sorted with original. O(nlogn)
        // idea 2: traverse forward, the last element that smaller than the max preceeding it, is to be sorted. traverse backward, the first 
        // element that larger than min after it is to be sorted. O(n)
        
        // implement idea 2
        
        int sort_end = -2;
        int max_val = nums[0];
        for(int i = 0; i < nums.size(); ++i)
        {
            if(max_val < nums[i])
                max_val = nums[i];
            else if(max_val > nums[i])
                sort_end = i;
        }
        
        int sort_start = -1;
        int min_val = nums[nums.size() - 1];
        for(int i = nums.size() - 1; i > -1; --i)
        {
            if(min_val > nums[i])
                min_val = nums[i];
            else if(min_val < nums[i])
                sort_start = i;
        }
        
        return max(sort_end - sort_start + 1, 0);
    }
};