class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // O(n) time, O(n) space
        // step 1: construct a dict: iterated_value -> count. 
        // map helps make elements unique. effectively a set will do the same thing, but we want counting info for k = 0 case
        // step 2: search in dict the pair element of each iterated value
        
        if(k < 0)
            return 0; // k is absolute difference
        
        unordered_map<int, int> rec;
        for(int i : nums)
            ++rec[i];
        
        int counter = 0;
        if(k != 0)
        {
            for(auto iter : rec)
            {
                if(rec.find(iter.first + k) != rec.end())
                    ++counter;
            }
        }
        else // k == 0
        {
            for(auto iter : rec)
            {
                if(iter.second > 1)
                    ++counter;
            }
        }
        
        
        return counter;
    }
};