ass Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largestNum = INT_MIN;
        int largestIndex = -1;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > largestNum) {
                largestNum = nums[i];
                largestIndex = i;
            }
        }
        
        for(int n : nums) {
            if(n == largestNum)
                continue;
            if(n * 2 > largestNum)
                return -1;
        }
        
        return largestIndex;
    }
};
