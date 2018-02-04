find maximum positive difference ranges in the array.

	traverse through the array, find the minimum (prices[i] <= prices[i - 1] && prices[i] < prices[i + 1]). buy at minimum. buyFlag = true.
	continue traversal. find maximum (prices[i] > prices[i - 1] && prices[i] >= prices[i + 1]). sell at maximum. buyFlag = false.
	
	finally, if buyFlag = true, sell at last price.
	
difficulty: handle a[0] and a[N-1] separately.