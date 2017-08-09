class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_sum = 0;
        int cur_sum = 0;
        for(int i : nums)
        {
            if(i)
                ++cur_sum;
            else
            {
                if(max_sum < cur_sum)
                    max_sum = cur_sum;
                cur_sum = 0;
            }
        }
        
        return max(max_sum, cur_sum);
    }
};