After one move, problem becomes N-1 (i2, j2) problem 
we can use recursion here. see recursion.cpp for details. exceeds time limits when N is large
but recursion will increase run time as each function call has overhead. we convert the logic to a loop



V2

Data structure: a 3D array. Res[N][i][j]
So e.g. res[12][3][5] stores numbers of paths we have, if given max 12 steps, start at(3,5)

So if initially, N=4, i = 3, j=2, 
res[4][3][2] = res[3][2][2] + res[3][4][2] + ... + ...
We record all (N, I, j) tuples until (1, I, j), which are easy to solve.

so reverse the order, we start from (1, i, j), then build up to (N, i, j). i.e. for each number of steps, we populate the m x n table which stores the number of path for each cell.

// calculate only until N - 1. so for N steps no need to calculate all cells.
for step from 1 to N - 1:
	for mi from 0 to m - 1:
		for ni from 0 to n - 1:
			res[step][mi][ni] = ((mi == 0)?1:[step - 1][mi - 1][ni])
                 + ((mi == m - 1)?1:[step - 1][mi + 1][ni])
                 + ((ni == 0)?1:[step - 1][mi][ni - 1])
                 + ((ni == n - 1)?1:[step - 1][mi][ni + 1]);		 
return ((i == 0)?1:[step - 1][i - 1][j])
                 + ((i == m - 1)?1:[step - 1][i + 1][j])
                 + ((j == 0)?1:[step - 1][i][j - 1])
                 + ((j == n - 1)?1:[step - 1][i][j + 1]);
				 
				 
trim the numbers to cap at 1000000007. i.e. numbers larger that this will lose some information.

V2 beat 78.38% in C++

