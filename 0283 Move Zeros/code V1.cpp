class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // keep two pointers - pt1 point to the first 0 we found, pt2 traverse through the list
        // complexity : O(n)
        
        if(nums.size() == 0)
            return;
        
        int pt1 = 0;
        int pt2 = 0;
        
        do {
            swap(nums[pt1], nums[pt2]);
            
            // look for 1st 0 left
            while(pt1 < nums.size() && nums[pt1] != 0)
                ++pt1;
            
            // look for 1st non-0
            pt2 = pt1 + 1;
            while(pt2 < nums.size() && nums[pt2] == 0)
                ++pt2;
            
            // if pt1 hit the end: no 0 left anymore
            // if pt2 hit the end: all numbers in the end are 0
            // in both cases, no need to swap anymore
        } while(pt1 < nums.size() && pt2 < nums.size());
    }
};