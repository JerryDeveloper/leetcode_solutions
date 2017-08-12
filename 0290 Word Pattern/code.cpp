class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        // seems map works faster than unordered_map
        
        stringstream ss(str);
        string word;
        int i = 0;
        int pattern_len = pattern.size();
        map<string, int> str_last_pos;
        map<char, int> pat_last_pos;
        
        while(ss >> word)
        {
            if(i == pattern_len) return false;
            if(str_last_pos[word] != pat_last_pos[pattern[i]])
                return false;
            str_last_pos[word] = i + 1;
            pat_last_pos[pattern[i]] = i + 1;
            ++i;
        }
        
        return i == pattern_len;  // if i < pattern_len, word is less than pattern. if i > pattern_len, false is returned in loop
    }
};