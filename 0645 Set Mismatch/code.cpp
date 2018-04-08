class Solution {
public:
    
    // put each number in nums at index = number - 1
    
    vector<int> findErrorNums(vector<int>& nums) {
        
        for(int& n : nums) {
            while(n != nums[n - 1]) {
                // loop until number in the n - 1's hole is n. so this will fix the first hole, then second, then third, etc
                int temp = nums[n - 1];
                nums[n - 1] = n;
                n = temp;
            }
        }
        
        int mistakeIndex = -1;
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != i + 1) {
                mistakeIndex = i;
                break;
            }
        
        return {nums[mistakeIndex], mistakeIndex + 1};
    }
};