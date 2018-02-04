class Solution {
public:
    
    // backtracking: tree node is the number. e.g. first level node is 2, next level children are 22, 23, 26, 27, children of 2 are 222, 223, 226, 227, children of 3 are 233, 236, 237...
    
    void combinationSumUtil(vector<int> &currCombination, int curSum, int startIndex, const vector<int>& candidates, const int target, vector<vector<int>> &res) {
        
        if(curSum > target)
            return;
        if(curSum == target) {
            res.push_back(currCombination);
            return;
        }
        
        if(startIndex == candidates.size()) {
            return;
        }
        
        for(int i = startIndex; i < candidates.size(); ++i) {
            currCombination.push_back(candidates[i]);
            combinationSumUtil(currCombination, curSum + candidates[i], i, candidates, target, res);
            currCombination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currCombination;
        for(int i = 0; i < candidates.size(); ++i) {
            currCombination.push_back(candidates[i]);
            combinationSumUtil(currCombination, candidates[i], i, candidates, target, res);
            currCombination.pop_back();
        }
        
        return res;
            
    }
};