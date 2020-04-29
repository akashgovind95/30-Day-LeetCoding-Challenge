/*
**Binary Tree Maximum Path Sum**

Given a non-empty binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

*/

/*
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

*/


class Solution {
public:
    int totalMaxSum = INT_MIN;
    int mps(TreeNode* root){
        if(!root)
            return 0;
        int left=mps(root->left);
        int right=mps(root->right);
        
        int currMaxSum = max(root->val, root->val+max(left,right));
        totalMaxSum = max(totalMaxSum,max(root->val + left + right, currMaxSum));
        return currMaxSum;
    }
    
    int maxPathSum(TreeNode* root) {
        mps(root);
        return totalMaxSum;
        
    }
};