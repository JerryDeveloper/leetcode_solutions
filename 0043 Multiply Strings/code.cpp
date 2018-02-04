class Solution {
public:
    // not a very efficient way. convert all multiplication to addition
    // https://leetcode.com/problems/multiply-strings/discuss/17605/
    // this is a much better way
    
    
    string sum(string num1, string num2) {
        
        int len1 = num1.size();
        int len2 = num2.size();
        
        int i1 = len1 - 1;
        int i2 = len2 - 1;
        int carry = 0;
        string res = "";
        while(i1 >= 0 || i2 >= 0) {
            int c1 = ((i1 >= 0)?(num1[i1] - '0'):0);
            int c2 = ((i2 >= 0)?(num2[i2] - '0'):0);
            int cur_sum = c1 + c2 + carry;
            char cur_digit = cur_sum % 10 + '0';
            carry = cur_sum / 10;
            res = cur_digit + res;
            --i1;
            --i2;
        }
        
        if(carry > 0) 
            res = char(carry + '0') + res;
        
        return res;
    }
    
    string multiply(string num1, string num2) {
        string res = "0";
        
        if(num1 == "0" || num2 == "0")
            return res;
        
        int len2 = num2.size();
        for(int i = len2 - 1; i >= 0; --i) {
            int cur_loops = num2[i] - '0';
            string cur_res = num1;
            if(cur_loops == 0) {
                cur_res = "0";
            }
            else {
                for(int j = 1; j < cur_loops; ++j) {
                    cur_res = sum(cur_res, num1);
                }
                // append 0s
                for(int j = 0; j < len2 - i - 1; ++j) {
                    cur_res = cur_res + '0';
                }
            }
            res = sum(res, cur_res);
        }
        
        return res;
    }
};