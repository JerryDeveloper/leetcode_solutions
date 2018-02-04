class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();
        
        int ptr_a = len_a - 1;
        int ptr_b = len_b - 1;
        
        int base = 2;   // can change to any base
        string res = "";
        int carry = 0;
        while(ptr_a >= 0 || ptr_b >= 0) {
            int char_a = (ptr_a >= 0?(a[ptr_a] - '0'):0);
            int char_b = (ptr_b >= 0?(b[ptr_b] - '0'):0);
            
            int sum = char_a + char_b + carry;
            int cur_digit = sum % base;
            carry = sum / base;
            
            res = char(cur_digit + '0') + res;
            
            --ptr_a;
            --ptr_b;
        }
        
        if(carry == 1)
            res = '1' + res;
        
        return res;
    }
};