Idea: 
The final objective is to find a cut point in A, which separates A into A1 and A2. Once cut point in A is fixed, the cut point in B is determined as well, let's say, B1 and B2. It follows that len(B1) + len(A1) = len(B2) + len(A2) if len(A) + len(B) is even, or len(B1) + len(A1) + 1 = len(B2) + len(A2) if is odd.

so we only need to search the array with smaller length. lets assume A has smaller length. In this case, we can always find a B cutpoint given A cutpoint.

during each search, 
if(A1[end] <= B2[start] && B1[end] <= A2[start])
	we find the cut point
else if(A1[end] <= B2[start] && B1[end] > A2[start])
	we need to move A cutpoint to right, making A2[start] larger, which automatically makes B1[end] smaller.
else if(A1[end] > B2[start] && B1[end] <= A2[start])
	we need to move A cutpoint to left

The case (A1[end] > B2[start] && B1[end] > A2[start]) is impossible.

for the search, we use binary search

complexity: O(ln(min(A, B)))

Some technical issues:
1. once cutpoints are found, what's the median? 
ans: if len(A) + len(B) is even, it's (max(A1[end], B1[end]) + min(A2[start], B2[start])) / 2. if odd, it's min(A2[start], B2[start])

2. how to represent cutpoint?
ans: use the index of first element of A2/B2. so 
A1 = A[0:cpA - 1], A2 = A[cpA:len(A) - 1]
B1 = B[0:cpB - 1], B2 = B[cpB:len(B) - 1]
len(A1) = cpA, len(A2) = len(A) - cpA
len(B1) = cpB, len(B2) = len(B) - cpB

3. what if A1/A2/B1/B2 is empty?
ans: for the above 3 conditions, if any of the A1/A2/B1/B2 does not exist, we do not need condition for that subpart, so can just skip the comparison 



C++ performance: beat 96%. very good
