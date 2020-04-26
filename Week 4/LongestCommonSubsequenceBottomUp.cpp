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
    int longestCommonSubsequence(string text1, string text2) {
        
        int s1 = text1.size();
        int s2 = text2.size();
        
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1));
        
        for(int i = 1 ;i<=s1;i++){
            for(int j = 1; j<=s2;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[s1][s2];
    }
};


int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    cout<<Solution().longestCommonSubsequence(text1,text2);
    return 0;
}
