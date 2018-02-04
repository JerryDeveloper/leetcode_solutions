inorder: left -> root -> right

a stack: store roots whose left tree are been traversed, and itself and right tree will be traversed in future.

	push top node to stack
	while stack is not empty:
		pop out a node
		if the node has left tree and has not been traversed: 
			push it back to stack
			push left child to stack
			continue
			
		print the node
		mark the node as been traversed
		if the node has right tree:
			push right child to stack
		
		
		
question: how to mark been traversed?
ans: since we cant modify the node structure, use an external data structure, e.g. a map or an unordered map

very bad. only beat 1.94% in c++


V2:
if we can make sure that, when poping out from stack, the node's left tree has been traversed, then we do not need the checklist. how?

when we push a node to stack, we are going to visit its left tree. so when we are back to this node, the left tree has been traversed. 
so instead of pushing children into stack(V1), we push current node into stack. and let current node = left node for next iteration.

still only beat 1.94%... i guess it's leetcode's problem. they do not distinguish runtime within a bin.