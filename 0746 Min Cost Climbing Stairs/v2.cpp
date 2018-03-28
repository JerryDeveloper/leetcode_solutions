class Solution {
public:
    // iterative approach
    
    // to reach step n (length of stages), the cost is minCost(n - 2) or minCost(n - 1)
    // to reach any step i, the cost is minCost(i - 2) + cost[i], or minCost(i - 1) + cost[i]
    // recursively traverse down
    
    // default value of minCost (memoization) is 0. length of the memoization is len(cost) + 1, to denote the non-existing end point. 
    int minCostClimbingStairs(vector<int>& cost) {
        
        if(cost.size() < 2)
            return 0;
        
        vector<int> minCost(cost.size(), 0);
        minCost[0] = cost[0];
        minCost[1] = cost[1];
        for(int i = 2; i < minCost.size(); ++i) {
            minCost[i] = min(minCost[i - 1] + cost[i], minCost[i - 2] + cost[i]);
        }
        
        return min(minCost[cost.size() - 1], minCost[cost.size() - 2]); // last stage, the non-existing end point
    }
};