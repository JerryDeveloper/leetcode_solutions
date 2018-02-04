class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // idea: traverse through s and t. two maps, one from s to t, one from t to s. if any character already mapped in s->t and t->s, is 
        // mapped to another character, in this case, it's not isomorphic. 
        // very slow.
        
        unordered_map<char, char> st;
        unordered_map<char, char> ts;
        
        for(int i = 0; i < s.size(); ++i)
        {
            if(st.find(s[i]) != st.end() && st[s[i]] != t[i])
                return false;
            if(ts.find(t[i]) != ts.end() && ts[t[i]] != s[i])
                return false;
            
            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }
        
        return true;
    }
};