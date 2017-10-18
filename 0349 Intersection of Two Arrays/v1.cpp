class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1_set;
        for(int n : nums1)
        {
            n1_set.insert(n);
        }

        set<int> res;
        for(int n : nums2)
        {
            if(n1_set.find(n) != n1_set.end())
                res.insert(n);
        }
        
        return vector<int>(res.begin(), res.end());
    }
};