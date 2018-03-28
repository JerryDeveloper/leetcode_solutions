ass Solution {
public:
    // recursive approach
    
    // to reach step n (length of stages), the cost is minCost(n - 2) or minCost(n - 1)
    // to reach any step i, the cost is minCost(i - 2) + cost[i], or minCost(i - 1) + cost[i]
    // recursively traverse down
    
    // default value of minCost (memoization) is 0. length of the memoization is len(cost) + 1, to denote the non-existing end point. 
    int minCostClimbingStairsUtil(const vector<int>& cost, const int curStep, vector<int>& minCost) {
        if(curStep < 0)
            return 0;
        
        if(minCost[curStep] != 0)
            return minCost[curStep];
        
        int oneStepPrevCost = minCostClimbingStairsUtil(cost, curStep - 1, minCost);
        int twoStepPrevCost = minCostClimbingStairsUtil(cost, curStep - 2, minCost);
        int curStepCost = (curStep == cost.size())?0:cost[curStep];
        minCost[curStep] = min(oneStepPrevCost + curStepCost, twoStepPrevCost + curStepCost);
        return minCost[curStep];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost(cost.size() + 1, 0);
        minCostClimbingStairsUtil(cost, cost.size(), minCost);
        return minCost[cost.size()];
    }
};
