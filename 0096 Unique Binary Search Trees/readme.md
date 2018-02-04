v1:
using 95's solution is fine. but it takes long. and encountered exceed time limit error.

v2:
since we only need to count number of trees, we can create a map to store calculated parameter pairs. to avoid repeating calculation.

beat only 3.34%. definitely not acceptable.

V3:
think about it: the number of BST constructed by [6, 10] = number of BST constructed by [1, 5]. so the implication is:
define count[m] = number of BST constructed by [1, m]. so 
num of BST constructed by [1, n], splitting at i, is count[1, i - 1] * count[i + 1, n]

performace is much better. get into the top tranch.