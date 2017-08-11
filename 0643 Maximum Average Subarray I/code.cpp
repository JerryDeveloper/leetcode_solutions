class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // idea: sliding window
        
        int cur_sum = 0;
        for(int i = 0; i < k; ++i)
            cur_sum += nums[i];
        
        int max_sum = cur_sum;
        for(int i = k; i < nums.size(); ++i)
        {
            int new_sum = cur_sum - nums[i - k] + nums[i];
            if(new_sum > max_sum)
                max_sum = new_sum;
            cur_sum = new_sum;
        }
        
        return double(max_sum) / k;
    }
};