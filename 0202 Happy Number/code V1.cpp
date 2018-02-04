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
        // idea: keep looping until hit any previously encountered number. Use unordered_set to teep track of the information
        
        unordered_set<int> already_encounted;
        while(already_encounted.find(n) == already_encounted.end())
        {
            already_encounted.insert(n);
            n = getDigitSquareSum(n);
            if(n == 1)
                return true;
        }
        
        return false;
    }
};