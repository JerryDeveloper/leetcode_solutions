class Solution {
public:
    
    // solution 1: backtracking. the tree node is the number. e.g. input "23". top node is 2, the edges from this node are "a", "b", "c"
    // then next level node is 3, following each of edge. the edges are "d", "e", "f"
    
    vector<string> letterCombinationsUtil(const map<char, vector<char>> & dict, const string & input, int curIndex, const vector<string> & res) {
        if(curIndex >= input.size())
            return res;
        
        vector<string> curRes;
        for(string s : res) {
            char curChar = input[curIndex];
            // vector<char> seq = dict[curChar]; // [] operator cannot be used on const map
            vector<char> seq = dict.at(curChar);
            for(char c : seq)
                curRes.push_back(s + c);
        }
        
        return letterCombinationsUtil(dict, input, curIndex + 1, curRes);
    }
    
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
        
        vector<string> res = {""};
        
        return letterCombinationsUtil(dict, digits, 0, res);
    }
};