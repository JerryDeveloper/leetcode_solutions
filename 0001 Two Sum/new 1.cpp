class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> t;
        for(int i = 0; i < nums.size(); ++i)
        {
            int diff = target - nums[i];
            if(t.count(diff) > 0)
            {
                return {t[diff], i};
            }
            else if(t.count(nums[i]) == 0)
            {
                t[nums[i]] = i;
            }
        }
        
        return {};
    }
};