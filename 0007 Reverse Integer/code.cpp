class Solution {    
public:
    int reverse(int x) {
        
        // one way is to use long as res type. 
        // here use another way
        
        int temp = x;
        if(x < 0)
            temp = -x;
        
        int res = 0;
        do {
            int curDigit = temp % 10;
            int remainder = temp / 10;
            
            if((INT_MAX - curDigit) / 10.0 < res)
                return 0;
            
            res = res * 10 + curDigit;
            temp = remainder;
        } while(temp != 0);
        
        return (x < 0)?-res:res;
    }
};