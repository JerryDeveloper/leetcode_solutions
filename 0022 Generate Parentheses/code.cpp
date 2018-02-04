class Solution {
public:
    
    // tree node: the current string. eg. first level is "(", second level is "((" or "()", children of "((" is "(((" or "(()" (3rd level)....
    
    void generateParenthesisUtil(int leftRemaining, int rightRemaining, string curString, vector<string> &res) {
        
        if(leftRemaining == 0 && rightRemaining == 0) 
        {
            // result
            res.push_back(curString);
            return;
        }
        if(leftRemaining > 0 && rightRemaining == 0)  // error
            return;
        
        if(leftRemaining > 0)
            generateParenthesisUtil(leftRemaining - 1, rightRemaining, curString + '(', res);
        if(rightRemaining > leftRemaining)
            generateParenthesisUtil(leftRemaining, rightRemaining - 1, curString + ')', res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res = {};
        
        if(n == 0)
            return res;
        
        generateParenthesisUtil(n - 1, n, "(", res);
        return res;
    }
};