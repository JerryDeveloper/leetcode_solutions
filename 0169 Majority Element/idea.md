The algorithm will always requires at least O(n) time complexity, since need to check each element to find/confirm majority.

simple idea is to use a dictionary to maintain count.

Moore's voting algorithm:
Each majority element pair with a non-majority element. we cancel out the pairs, the remaining element, if any, must be a majority element.
This algorithm works only when:
1. the majority element do exist. the question assumes this
2. number of majority element is over half of total length. e.g. if 8 numbers, majority element must have at least 5. otherwise [4,4,4,4,1,2,3,5] will not work. The question said majority element is more than n/2. so this satisfies also.

