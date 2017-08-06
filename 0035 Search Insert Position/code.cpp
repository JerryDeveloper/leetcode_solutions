class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // use binary search
        
        int begin = 0;
        int end = nums.size() - 1;
        int last_searched_index = begin;
        
        while(end >= begin) {
            int mid = (begin + end) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            last_searched_index = mid;
            if(nums[mid] > target)
                end = mid - 1;
            else
                begin = mid + 1;
        }
        
        if(nums.size() == 0 || nums[last_searched_index] > target)
            // empty list or last searched index larger than target, insert at the position
            return last_searched_index;
        else if(nums[last_searched_index] < target)
            // last searched index smaller than target
            return last_searched_index + 1;
    }
};