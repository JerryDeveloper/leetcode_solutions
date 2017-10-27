class Solution {
public:
    int maxArea(vector<int>& height) {
        // denote a1 and an, move i from 1 to n, j from n to 1.
        // we (a1, ai) and (aj, an) definitely smaller than (a1, an).
        // so we only need to check whether (ai, aj) is larger than (a1, an). 
        // this is possible only when ai > a1, aj > an
        
        int n = height.size();
        int max_area = 0;
        
        int i = 0;
        int j = n - 1;
        
        while(i < j)
        {
            int h = min(height[i], height[j]);
            max_area = max(h * (j - i), max_area);
        
            while(i < j && height[i] <= h)
                ++i;
            while(i < j && height[j] <= h)
                --j;
        }
        
        return max_area;
        
        // sth to think about: if the base is not x-axis, but the blocks. how?
    }
};