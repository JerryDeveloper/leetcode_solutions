class Solution {
public:
    
    // solution 2: use queue. pop out previously generated string, and append the new char to the result. and push back.
    

    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0)
            return {};
        
        map<char, vector<char>> dict;
        dict['2'] = {'a', 'b', 'c'};
        dict['3'] = {'d', 'e', 'f'};
        dict['4'] = {'g', 'h', 'i'};
        dict['5'] = {'j', 'k', 'l'};
        dict['6'] = {'m', 'n', 'o'};
        dict['7'] = {'p', 'q', 'r', 's'};
        dict['8'] = {'t', 'u', 'v'};
        dict['9'] = {'w', 'x', 'y', 'z'};
        
        queue<string> res;
        
        string curString = "";
        int curIndex = 0;
        do {
            for(char c : dict[digits[curIndex]])
                res.push(curString + c);
            string temp = res.front();
            
            if(temp.size() > curString.size())
                ++curIndex;
            
            curString = temp;
            
            if(curIndex < digits.size()) {
                res.pop();
            } 
        }while(curIndex < digits.size());
        
        vector<string> result;
        while (!res.empty())
        {
            result.push_back(res.front());
            res.pop();
        }
        
        return result;
    }
};