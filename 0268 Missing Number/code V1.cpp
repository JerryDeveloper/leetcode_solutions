class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int lens = nums.size();
        
        for(int i : nums)
            sum += i;
        
        return lens * (lens + 1) / 2 - sum;
    }
};