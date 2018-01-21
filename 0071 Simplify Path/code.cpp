class Solution {
public:
    string simplifyPath(string path) {
        stack<string> prev_folders;
        stringstream ss(path);
        string cur;
        while(getline(ss, cur, '/')) {
            if(cur == "..") {
                if(!prev_folders.empty())
                    prev_folders.pop();  // assume path is correct
            }
            else if(!cur.empty() && cur != ".") {
                prev_folders.push(cur);
            }
        }

        string res = "";
        while(!prev_folders.empty()) {
            res = "/" + prev_folders.top() + res;
            prev_folders.pop();
        }
        
        return res.empty()?"/":res;
    }
};