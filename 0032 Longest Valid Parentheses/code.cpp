class Solution {
public:
    
    // initialize : res[0] = 0
    // suppose current index = i
    // if s[i] is '(', then res[i] = res[i - 1], because a single '(' cannot form a valid parentheses
    // else if s[i] is ')', then we need to count whether there are unmatched '('. ues a stack to store j = the index of latest unmatched '('. after poping j out, we get latest unmatched '(' or ')', at index k. from k + 1 to i is a valid sequence. if it's longer than res[i - 1], res[i] == i - k. else, res[i] = res[i - 1]
    
    int longestValidParentheses(string s) {
        
        if(s.empty())
            return 0;
        
        int res[s.size()] = {};
        stack<int> unmatched; // include unmatched '('
        int wrong_char = -1; // latest unmatched index of ')'. e.g. ())
        res[0] = 0;
        if(s[0] == '(')
            unmatched.push(0);
        else
            wrong_char = 0;
        
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == '(') {
                res[i] = res[i - 1];
                unmatched.push(i);
            }
            else if(unmatched.empty()) {
                res[i] = res[i - 1];
                wrong_char = i;
            }
            else {
                unmatched.pop();  // delete the '(' matching current ')'
                int k1 = (unmatched.empty()?-1:unmatched.top());
                int k = max(k1, wrong_char);
                res[i] = max(res[i - 1], i - k);
            }
        }
        
        return res[s.size() - 1];
    }
};