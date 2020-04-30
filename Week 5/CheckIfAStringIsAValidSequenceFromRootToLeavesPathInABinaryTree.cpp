/*
Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/532/week-5/3315/

Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree. 
We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void ivs(TreeNode* root, vector<int>& arr, int idx, bool &res){
        if(idx==arr.size()-1 && arr[idx] == root->val){
            if(!root->left && !root->right)
                res=true;
        }
        
        else{
             if(root->val == arr[idx]){
                 if(root->left)
                     ivs(root->left,arr,idx+1,res);
                 if(root->right)
                     ivs(root->right,arr,idx+1,res);
             }
        }
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        bool res = false;
        ivs(root,arr,0,res);
        return res;
    }
};