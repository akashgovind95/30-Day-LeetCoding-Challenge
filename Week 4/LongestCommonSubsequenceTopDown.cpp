/*
Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lcs(string &text1,string &text2,int idx1,int idx2,vector<vector<int>> &dp){
        
        if(idx1==text1.size() || idx2==text2.size())
            return 0;
        
        if(dp[idx1][idx2]!= 0 )
            return dp[idx1][idx2];
        
        if(text1[idx1] == text2[idx2])
            return dp[idx1][idx2] = 1+lcs(text1,text2,idx1+1,idx2+1,dp);
        else
            return dp[idx1][idx2]  = max(lcs(text1,text2,idx1+1,idx2,dp),lcs(text1,text2,idx1,idx2+1,dp));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1)); 
        return lcs(text1,text2,0,0,dp);
        
    }
};

int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    cout<<Solution().longestCommonSubsequence(text1,text2);
    return 0;
}
