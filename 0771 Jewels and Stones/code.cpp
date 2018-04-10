class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewels;
        for(const char& c: J) 
            jewels.insert(c);
        
        int res = 0;
        for(const char& c: S) {
            if(jewels.find(c) != jewels.end())
                ++res;
        }
        
        return res;
    }
};