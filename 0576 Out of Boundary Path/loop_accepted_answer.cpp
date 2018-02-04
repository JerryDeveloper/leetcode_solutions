class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        
        if(N == 0)
            return 0;
        
        unsigned long long res[N][m][n] = {};
        
        for(int step = 1; step < N; ++step)
            for(int mi = 0; mi < m; ++mi)
                for(int ni = 0; ni < n; ++ni)
                    res[step][mi][ni] = (((mi == 0)?1:res[step - 1][mi - 1][ni])
                                     + ((mi == m - 1)?1:res[step - 1][mi + 1][ni])
                                     + ((ni == 0)?1:res[step - 1][mi][ni - 1])
                                     + ((ni == n - 1)?1:res[step - 1][mi][ni + 1])) % 1000000007;
        return (((i == 0)?1:res[N - 1][i - 1][j])
                 + ((i == m - 1)?1:res[N - 1][i + 1][j])
                 + ((j == 0)?1:res[N - 1][i][j - 1])
                 + ((j == n - 1)?1:res[N - 1][i][j + 1])) % 1000000007;
    }
};