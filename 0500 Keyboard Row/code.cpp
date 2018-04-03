ass Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> charGroup;
        for(const char& c : "qwertyuiop")
            charGroup[c] = 1;
        for(const char& c : "asdfghjkl")
            charGroup[c] = 2;
        for(const char& c : "zxcvbnm")
            charGroup[c] = 3;
         
        vector<string> res;
        for(const string& word : words) {
            set<int> groups;
            for(const char& c: word)
                groups.insert(charGroup[tolower(c)]);
            if(groups.size() == 1)
                res.push_back(word);
        }
        
        return res;
    }
};
