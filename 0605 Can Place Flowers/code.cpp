class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // idea 1: traverse forward and plant at earliest possible slot. O(n)
        
        for(int i = 0; i < flowerbed.size() && n > 0; ++i)
        {
            if(flowerbed[i] == 1)
                continue;
            
            if((i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                --n;
            }
        }
        
        return n == 0;
    }
};