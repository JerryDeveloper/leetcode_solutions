class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pt1 = 0;
        int pt2 = 0;
        
        // trim nums1
        nums1.erase(nums1.begin() + m, nums1.end());
        
        while(pt2 != n)
        {
            if(nums1[pt1] < nums2[pt2] && pt1 < nums1.size())
            {
                ++pt1;
                continue;
            }
            
            // find the first element in nums1 larger than current pt2, and insert current pt2 to that position
            nums1.insert(nums1.begin() + pt1, nums2[pt2]);
            ++pt2;
            ++pt1;
            
        }
    }
};