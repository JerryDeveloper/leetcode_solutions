class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // maintain three variables: first, second, third, to record the first three largest numbers. and traverse through array and update
        // the three variables
        // it's possible that the nums contains INT_MIN, so we use long type to check INT_MIN
        
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        
        for(int i : nums)
        {
            if(i > first)
            {
                third = second;
                second = first;
                first = i;
            }
            else if(i > second && i < first)
            {
                third = second;
                second = i;
            }
            else if(i > third && i < second)
            {
                third = i;
            }
        }
        
        return (third == LONG_MIN)? first : third;
    }
};