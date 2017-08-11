class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // idea 1: sort, find the first 3 and last 3 numbers combinations
        // idea 2: actually only need to find top and bottom 3 numbers, no need to sort.
        // in general, need s1,s2,s3, the smallest 3, and l1,l2,l3, the largest 3. maximum is one of s1,s2,l1 and l1,l2,l3
        
        int s1 = INT_MAX;
        int s2 = INT_MAX;
        int s3 = INT_MAX;
        
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int l3 = INT_MIN;
        
        for(int i : nums)
        {
            // update largest values
            if(i > l1)
            {
                l3 = l2;
                l2 = l1;
                l1 = i;
            }
            else if(i > l2)
            {
                l3 = l2;
                l2 = i;
            }
            else if(i > l3)
            {
                l3 = i;
            }
            
            // update smallest values
            if(i < s1)
            {
                s3 = s2;
                s2 = s1;
                s1 = i;
            }
            else if(i < s2)
            {
                s3 = s2;
                s2 = i;
            }
            else if(i < s3)
            {
                s3 = i;
            }
        }
        
        return max(s1 * s2 * l1, l1 * l2 * l3);
    }
};