class Solution {
private:
    struct TrieNode {
        char val;
        map<char, TrieNode*> children;
        bool isEndOfWord;
        
        TrieNode(char val) : val(val), isEndOfWord(false) {}
    };
    
    string longestWordUtil(TrieNode* cur) {
        if(!cur->isEndOfWord)
            return "";
        
        string curVal(1, cur->val);
        string res = curVal;
        for(auto& child : cur->children) {
            string temp = curVal + longestWordUtil(child.second);
            if(temp.size() > res.size() || (temp.size() == res.size() && temp.compare(res) < 0))
                res = temp;
        }
        
        return res;
    }
    
public:
    
    // 1. sort then traverse (O(nlogn))
    // 2. construct a trie structure, then then DFS to find the deepest char to which from root all nodes along the way are endOfWord
    
    string longestWord(vector<string>& words) {
        
        // construct the trie
        TrieNode* root = new TrieNode(0);
        for(const string& word : words) {
            TrieNode* cur = root;
            for(const char& c: word) {
                if(cur->children.find(c) == cur->children.end()) {
                    cur->children[c] = new TrieNode(c);
                }
                cur = cur->children[c];
            }
            cur->isEndOfWord = true;
        }
        
        // DFS
        string res = "";
        for(auto& child : root->children) {
            string temp = longestWordUtil(child.second);
            if(temp.size() > res.size() || (temp.size() == res.size() && temp.compare(res) < 0))
                res = temp;
        }
        
        return res;
    }
};