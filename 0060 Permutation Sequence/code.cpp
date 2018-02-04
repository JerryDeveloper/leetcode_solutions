class Solution {
public:
    
    // this question does not need backtracking, we can calculate the k-th permutation
    
    set<int> digitsTaken;
    
    int factorial(int n) {
        if(n == 0)
            return 1;
        
        int res = 1;
        while(n > 0) {
            res *= n;
            --n;
        }
        
        return res;
    }
    
    string getPermutation(int n, int k) {
        
        int remainder;
        vector<int> availableDigits;
        
        for(int i = 1; i <= n; ++i)
            availableDigits.push_back(i);
        
        string res = "";
        for(int i = 1; i <= n; ++i) {
            int numPerm = factorial(n - i);
            int numBlocks = (k - 1) / numPerm;
            int curDigit = availableDigits[numBlocks];
            availableDigits.erase(availableDigits.begin() + numBlocks);
            
            k -= numBlocks * numPerm;
            
            res += to_string(curDigit);
        }
        
        return res;
    }
};