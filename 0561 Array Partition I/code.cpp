class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // sort the array and add up odd position numbers
        // intuition: if second largest number is not paired with largest number, it will not be included in the sum. sum will be smaller. 
        // similar to 4th, 6th ... largest number
        
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i += 2)
            sum += nums[i];
        
        return sum;
    }
};