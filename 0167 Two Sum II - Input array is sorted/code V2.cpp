class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // no need to traverse element. keep two pointers at the beginning and end of array. if sum is too small, move beginning pointer,
        // if sum is too large, move end pointer
        
        int begin = 0;
        int end = numbers.size() - 1;
        
        while(begin <= end)
        {
            int sum = numbers[begin] + numbers[end];
            if(sum == target)
                return {begin + 1, end + 1};
            else if(sum < target)
                ++begin;
            else
                --end;
        }
        
        return {0, 0}; // could not find
    }
};