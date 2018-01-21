class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int i = s.size() - 1;
        
        // escape all spaces
        for(; i >= 0; --i) {
            if(!isspace(s[i]))
                break;
        }
        
        for(; i >= 0; --i) {
            if(isspace(s[i]))
                return res;
            else
                ++res;
        }
        
        return res;
    }
};