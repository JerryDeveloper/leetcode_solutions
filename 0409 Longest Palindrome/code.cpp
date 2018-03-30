ass Solution {
public:
    
    // count number of each letter
    // all even counts can be used, all odd count - 1 can be used.
    // if at least one odd count, result + 1
    
    int longestPalindrome(string s) {
        map<char, int> counter;
        for(const char& c : s)
            ++counter[c];
        
        int res = 0;
        int numOdd = 0;
        for(const pair<char, int>& p : counter) {
            if(p.second % 2 == 0)
                res += p.second;
            else {
                res += p.second - 1;
                ++numOdd;
            }
        }
        
        if(numOdd > 0)
            ++res;
        
        return res;
    }
};
