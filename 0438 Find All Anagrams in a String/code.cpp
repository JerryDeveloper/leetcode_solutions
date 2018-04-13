class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
        map<char, int> counter;
        for(char c : p) 
            ++counter[c];
        
        int left = 0;
        int right = 0;
        int length = p.size();
        
        vector<int> res;
        res.reserve(max(static_cast<int>(s.size() - p.size()), 0));
        
        while(right < s.size()) {
            
            char curRight = s[right];
            if(counter[curRight] > 0) {
                --length;
            }
            --counter[curRight]; // possible to become negative
            ++right;
            
            if(length == 0)
                res.push_back(left);
            
            char curLeft = s[left];
            if(right - left == p.size()) {
                
                // if a char is not in p, when left pointer encounters it, the right pointer encounters it already, so the count will surely be negative
                // the char will never affect length
                
                if(counter[curLeft] >= 0) {
                    ++length;
                }
                
                ++counter[curLeft];
                ++left;
            }
        }
        
        return res;
    }
};