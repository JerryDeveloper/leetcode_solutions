Idea: 
1. maintain two pointers, i and j, i points to the start of current substring, j points to the char currently at. 
2. maintain a pair cur_res = (start, end), record current longest substring found.
3. for s[j], check whether it appears in s[k] (i <= k < j) (implementation in step 4). 
if s[k] = s[j], 
	if len(i:j-1) > len(cur_res), cur_res = (i, j-1). 
	update i to k + 1 (new start of current substring). continue j-traversal
else, continue j-traversal.

Step 3 ensures one-time traversal over string (by j).

4. maintain a hashtable that stores the largest index of each char in string. so to check whether s[j] is in current substring, just largest index of s[j] in the table is >= i. this loop up time is constant
note in step 4, i used 1-based index. e.g, 'abcde', in table t['b'] = 1 not 0. it is because t['f'] will return 0 although 'f' is not in the table.

complexity: O(n)

note: if largest substring is the last part of s, cur_res will not get updated. so at the end need additional handling.

C++: only beat 33%