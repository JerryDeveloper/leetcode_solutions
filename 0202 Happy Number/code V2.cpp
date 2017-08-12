class Solution {
public:
    int getDigitSquareSum(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int cur_digit = n % 10;
            sum += cur_digit * cur_digit;
            n = n / 10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {
        // idea 2: Floyd Cycle detection: basically we are checking whether there is any cycle. we could keep two pointers along the 
        // sequence, one faster the other one slower. if there's cycle, ultimately both will meeting. In this case we dont need the set any 
        // more
        
        int slow = n;
        int fast = n;
        do
        {
            if(slow == 1)
                return true;
            slow = getDigitSquareSum(slow);
            fast = getDigitSquareSum(getDigitSquareSum(fast));
        } while(slow != fast);
        
        return slow == 1;
    }
};