class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int cur_res = 0;
        map<char, int> t;
        
        int len = s.length();
        
        for(; j < len; ++j)
        {
            int check_idx = t[s[j]];
            if(check_idx > 0 && check_idx - 1 >= i)
            {
                // found duplicate
                if(j - i > cur_res)
                {
                    cur_res = j - i;  
                }
                
                i = check_idx;
            }
            
            
            t[s[j]] = j + 1;   // maintain s[j]'s latest index. 1-based
            
        }
        
        // check last part of s
        if(len - i > cur_res)
            cur_res = len - i;
        
        return cur_res;
    }
};