class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum_until_prev_element = nums[0];
        int max_sum = nums[0];
        
        for(int i = 1; i < nums.size(); ++i)
        {
            // if sum until previous element is less than 0, it will drag down current element value. so we discard previous subarray
            if(sum_until_prev_element < 0)
                sum_until_prev_element = nums[i];
            else
                sum_until_prev_element = sum_until_prev_element + nums[i];
            
            max_sum = max(sum_until_prev_element, max_sum);
        }
        
        return max_sum;
    }
};a