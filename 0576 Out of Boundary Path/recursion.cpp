// Time limit exceeded when inputs are large

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if(N == 0)
        {
            return 0;
        }
        else
        {
            unsigned long long res = ((i == 0)?1:findPaths(m, n, N - 1, i - 1, j))
                 + ((i == m - 1)?1:findPaths(m, n, N - 1, i + 1, j))
                 + ((j == 0)?1:findPaths(m, n, N - 1, i, j - 1))
                 + ((j == n - 1)?1:findPaths(m, n, N - 1, i, j + 1));
            return res % 1000000007;
        }
    }
};