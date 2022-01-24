### O(N square) approach
- The first element of preorder traversal is always root.
- We first construct the root.
- Then we find the index of the first element which is greater than the root.
- Let the index be ‘i’. The values between root and ‘i’ will be part of the left subtree, and the values between ‘i'(inclusive) and ‘n-1’ will be part of the right subtree. 
- Divide given pre[] at index “i” and recur for left and right sub-trees.
