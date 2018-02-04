class Solution {
public:
    
    // use a hashmap to count the usage of each word
    // two periods. in searching period, there's no match found yet. in matching period, we are matching the words
    
    void resetUsage(map<string, int> &usage) {
        for(auto &u : usage)
            u.second = 0;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;
        if(words.empty())
            return res;
        
        int word_len = words[0].size();
        int num_words = words.size();
        int s_len = s.size();
        
        map<string, int> counter;
        for(string w : words)
            ++counter[w];
        map<string, int> usage;
        resetUsage(usage);
        
        int slow_ptr = 0;
        int match_ptr = 0;
        int matched_words = 0;
        bool match_found = false;
        while(slow_ptr <= s_len - word_len * num_words) {
            
            if(!match_found) {
                // in searching period
                string next_substr = s.substr(slow_ptr, word_len);
                if(counter.find(next_substr) != counter.end()) {
                    // find a match
                    match_ptr = slow_ptr + word_len;
                    match_found = true;
                    ++usage[next_substr];
                    matched_words = 1; // start a match period
                }
                else 
                    ++slow_ptr;
            }
            else {
                // in matching period
                int res_size = res.size();
                if(matched_words == num_words) {
                    // found a match
                    res.push_back(slow_ptr);
                    resetUsage(usage);
                    match_found = false;
                    ++slow_ptr;
                    matched_words = 0;
                    continue;
                }
                if(match_ptr + word_len > s_len) {
                    // out of bound but not all words are matched
                    resetUsage(usage);
                    match_found = false;
                    ++slow_ptr;
                    matched_words = 0;
                    continue;
                }
                
                string next_substr = s.substr(match_ptr, word_len);
                if(counter.find(next_substr) != counter.end() && usage[next_substr] < counter[next_substr]) {
                    // match not complete but next substring is an unused word in words
                    match_ptr += word_len;
                    ++usage[next_substr];
                    ++matched_words;
                }
                else {
                    // concatenation not fully matched, but next substring is not in word. this block can be combined with second block (match_ptr + word_len > s_len). but to make logic clear I separated them
                    resetUsage(usage);
                    match_found = false;
                    ++slow_ptr;
                    matched_words = 0;
                }
            }
        }
        
        return res;
    }
};