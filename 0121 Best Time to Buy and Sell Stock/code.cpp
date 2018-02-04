class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // method 1. take difference between consequential prices, and apply the max subarray algorithm
        // method 2. find the global min and max
        
        // here we use method 2. min always before max. if we find a smaller min compared with current min, set the smaller min as current
        // min, and calculate the profit until the new current min. and look for max thereafter.
        
        if(prices.size() == 0)
            return 0;
        
        int cur_min = prices[0];
        int cur_max = prices[0];
        int max_profit = 0;
        
        for(int i = 1; i < prices.size(); ++i)
        {
            if(cur_min > prices[i])
            {
                // reset to find new range
                max_profit = max(max_profit, cur_max - cur_min);
                cur_min = prices[i];
                cur_max = prices[i];
            }
            else if(cur_max < prices[i])
            {
                cur_max = prices[i];
            }
        }
        
        return max(max_profit, cur_max - cur_min);
    }
};