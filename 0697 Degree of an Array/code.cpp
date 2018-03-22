struct NumInfo {
    int counter = 0;
    int startIndex = -1;
    int endIndex = -1;
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        int maxLen = 0;
        map<int, NumInfo> counter;
        
        for(int i = 0; i < nums.size(); ++i) {
            ++counter[nums[i]].counter;
            counter[nums[i]].endIndex = i;
            if(counter[nums[i]].startIndex == -1)
                counter[nums[i]].startIndex = i;
            
            if(counter[nums[i]].counter > maxLen) 
                maxLen = counter[nums[i]].counter;
        }
        
        // second loop on counter to find the subarray
        int shortestLen = INT_MAX;
        for(auto m = counter.begin(); m != counter.end(); ++m) {
            NumInfo temp = m->second;
            if(temp.counter < maxLen)
                continue;
            if(temp.endIndex - temp.startIndex + 1 < shortestLen)
                shortestLen = temp.endIndex - temp.startIndex + 1;
        }
        
        return shortestLen;
    }
};
