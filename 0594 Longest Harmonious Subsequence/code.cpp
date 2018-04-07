class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> counter;
        for(const int& i : nums) 
            ++counter[i];
        
        vector<int> keys;
        transform(counter.begin(), counter.end(), back_inserter(keys), [](const pair<int, int>& p) { return p.first; });
        
        if(keys.empty())
            return 0;
        
        int res = 0;
        for(int i = 1; i < keys.size(); ++i) {
            if(abs(keys[i] - keys[i - 1]) > 1) 
                continue;
            int temp = counter[keys[i]] + counter[keys[i - 1]];
            
            if(temp > res)
                res = temp;
        }
        
        return res;
    }
};