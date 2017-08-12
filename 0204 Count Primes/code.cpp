class Solution {
public:
    int countPrimes(int n) {
        if(n < 2)
            return 0;
        
        vector<short> isPrime (n, 1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        
        for(int i = 2; i < sqrt(n); ++i)
        {
            if(isPrime[i] == 1)
            {
                for(int j = i * i; j < n; j += i)
                {
                    isPrime[j] = 0;
                }
            }
        }
        
        return accumulate(isPrime.begin(), isPrime.end(), 0);
    }
};