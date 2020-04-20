/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int index = 0;
    TreeNode *const_bst(vector<int>& preorder,int parent_value){
        
        int curr_val = preorder[index];
        TreeNode* temp = new TreeNode(curr_val);

        if( index+1 < preorder.size() && preorder[index+1]<curr_val){
            index++;
            temp->left = const_bst(preorder,curr_val);
        }
        
        if( index+1 < preorder.size() && preorder[index+1]<parent_value){
            index++;
            temp->right = const_bst(preorder,parent_value);
        }
        
        return temp;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return const_bst(preorder,2147483647); //passing INT_MAX
        
    }
};

//utility function to print tree in level order traversal
string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main()
{
    vector<int> vec = {8,5,1,7,10,12};
    TreeNode * root = Solution().bstFromPreorder(vec);
    cout<<treeNodeToString(root); //printing tree in level order traversal
    return 0;
}
