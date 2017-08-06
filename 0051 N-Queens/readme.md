find solution recursively. within each recursion, loop through each row, check if we put a queen on a cell, whether there's any conflict. if we could not find any solution within the row (return false), we revert back to previous row

findQueens(solution_set, row):
	if row == N:
		push current solution to solution set
		return true; // found a solution
		
	for each cell in row:
		put queen on the cell
		findQueens(solution_set, row + 1)