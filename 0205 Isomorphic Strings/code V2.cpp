class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // idea: at each position, the two chars previous position must be same (position start from 1). so prev_pos == 0 means this 
        // character never appear before.
        
        // still slow. seems that map is not a good option
        
        unordered_map<char, int> s_prev_pos;
        unordered_map<char, int> t_prev_pos;
        
        for(int i = 0; i < s.size(); ++i)
        {
            if(s_prev_pos[s[i]] != t_prev_pos[t[i]])
                return false;
            
            s_prev_pos[s[i]] = i + 1;
            t_prev_pos[t[i]] = i + 1;
        }
        
        return true;
    }
};