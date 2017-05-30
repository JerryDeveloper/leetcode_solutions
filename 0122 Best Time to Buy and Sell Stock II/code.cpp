class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int size = prices.size();
        
        if(size < 2)
        {
            return 0;
        }
        
        bool buyFlag = false;
        int buyPrice = 0;
        int result = 0;
        
        if(prices[0] < prices[1])
        {
            buyFlag = true;
            buyPrice = prices[0];
        }
        
        for(int i = 1; i < size - 1; ++i)
        {
            if(!buyFlag && prices[i] <= prices[i - 1] && prices[i] < prices[i + 1])
            {
                buyFlag = true;
                buyPrice = prices[i];
            }
            else if(buyFlag && prices[i] > prices[i - 1] && prices[i] >= prices[i + 1])
            {
                buyFlag = false;
                result += (prices[i] - buyPrice);
            }
        }
        
        if(buyFlag)
            result += (prices[size - 1] - buyPrice);
            
        return result;
    }
};