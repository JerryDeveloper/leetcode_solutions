class Solution {
public:
    
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n == -1)
            return 1 / x;
        
        double t = myPow(x, n / 2);
        if(n % 2 == 0)
            return t * t;
        else if(n < 0)
            return t * t / x;
        else
            return t * t * x;
    }
};