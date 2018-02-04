class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 2; i <= n; ++i) {
            string tmp = "";
            
            char cur_char = res[0];
            int cur_count = 1;
            for(int j = 1; j < res.size(); ++j) {
                if(res[j] == cur_char)
                    ++cur_count;
                else {
                    tmp += to_string(cur_count) + cur_char;
                    cur_count = 1;
                    cur_char = res[j];
                }
            }
            
            res = tmp + to_string(cur_count) + cur_char;
        }
        
        return res;
    }
};