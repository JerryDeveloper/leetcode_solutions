class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // assume both list cannot be empty together, since question did not specify what to return in this case
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if(len1 == 0)
            return (len2 % 2 == 0)?((nums2[len2/2 - 1] + nums2[len2/2]) / 2.0):(nums2[len2/2]);
        if(len2 == 0)
            return (len1 % 2 == 0)?((nums1[len1/2 - 1] + nums1[len1/2]) / 2.0):(nums1[len1/2]);
        
        // A always shorter than B
        const vector<int> &A = (len1 < len2)?nums1:nums2;
        const vector<int> &B = (len1 >= len2)?nums1:nums2;
        int lenA = (len1 < len2)?len1:len2;
        int lenB = (len1 >= len2)?len1:len2;
        
        bool isEven = (lenA + lenB) % 2 == 0;
        
        // A binary search
        int startA = 0;
        int endA = lenA;
        
        int cpA = 0;
        int cpB = 0;
        while(startA <= endA)
        {
            cpA = (startA + endA) / 2;
            int lenA1 = cpA;
            int lenA2 = lenA - cpA;
            cpB = isEven?((lenB + lenA2 - lenA1) / 2):((lenB + lenA2 - lenA1 - 1) / 2);
            
            if((cpA == 0 || cpB == lenB || A[cpA - 1] <= B[cpB]) && (cpB == 0 || cpA == lenA || B[cpB - 1] <= A[cpA]))
            {
                int left_var = (cpA == 0)?B[cpB - 1]:((cpB == 0)?A[cpA - 1]:std::max(B[cpB - 1], A[cpA - 1]));
                int right_var = (cpA == lenA)?B[cpB]:((cpB == lenB)?A[cpA]:std::min(B[cpB], A[cpA]));
                
                return isEven?((left_var + right_var) / 2.0):(right_var);
            }
            else if((cpA == 0 || cpB == lenB || A[cpA - 1] <= B[cpB]) && (cpB == 0 || cpA == lenA || B[cpB - 1] > A[cpA]))
            {
                startA = cpA + 1;
            }
            else if((cpA == 0 || cpB == lenB || A[cpA - 1] > B[cpB]) && (cpB == 0 || cpA == lenA || B[cpB - 1] <= A[cpA]))
            {
                endA = cpA - 1;
            }
            
        }
        
        return -1;
    }
};