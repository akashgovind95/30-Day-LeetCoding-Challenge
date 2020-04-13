/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5   
      
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/


/*
Approach: 

1. Recurse the tree. For each node, find depth of left subtree and right subree.
2. Diameter  = max(leftDepth + rightDepth, Diameter)
3. Return maximum of leftDepth and rightDepth

*/


// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{

public:
  int Diameter;
  int depthOfTree (TreeNode * node)
  {
    if (!node)
      return 0;
    int leftDepth = 0;
    int rightDepth = 0;
    if (node->left)
        leftDepth = 1 + depthOfTree (node->left);
    if (node->right)
        rightDepth = 1 + depthOfTree (node->right);
    if (leftDepth + rightDepth > Diameter)
        Diameter = leftDepth + rightDepth;
      return max (leftDepth, rightDepth);

  }
  int diameterOfBinaryTree (TreeNode * node)
  {
    Diameter = 0;
    return max (Diameter, depthOfTree (node));

  }
};
