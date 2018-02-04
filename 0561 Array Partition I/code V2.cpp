class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // always need to sort, but we can use a more efficient way. since type is int, we use counting sort and no need to 
        // do the actual sorting
        
        // perform worse. reason is maintaining the map takes sometime (by a tree)
        // another way is to hard code the length of rec: 20001 (since numbers range from [-10000, 10000])
        
        map<int, int> rec;
        for(int i : nums)
            ++rec[i];
        
        int sum = 0;
        int cum_count = 0;
        
        for(auto iter : rec)
        {
            if(cum_count % 2 == 0) // cumulative count from previous is even
                sum += iter.first * ((iter.second + 1) / 2);
            else
                sum += iter.first * (iter.second / 2);
            
            cum_count += iter.second;
        }
        
        return sum;
    }
};