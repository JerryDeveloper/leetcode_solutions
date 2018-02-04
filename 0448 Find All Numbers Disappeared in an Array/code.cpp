class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // the numbers and indexes have one-to-one correspondence. so the idea is: for every number we iterate through, e.g. num, we mark
        // corresponding element with index = num to negative value of original value (first iteration). in second iteration, through indexes         // with values not -1, are missing numbers
        // the reason of setting to negative value is that we want to perserve the value information
        
        for(int i = 0; i < nums.size(); ++i)
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] > 0)
                result.push_back(i + 1);
    
        return result;
    }
};