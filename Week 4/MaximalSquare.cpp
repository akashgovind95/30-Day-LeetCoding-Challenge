/*Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:
Input: 
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Output: 4
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& mat) {
        
        if(mat.empty())
            return 0;
        int rows = mat.size();
        int cols = mat[0].size();
    
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1));
        int maxSqSize = 0;
        for(int i =1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                if(mat[i-1][j-1]=='1'){
                    dp[i][j]= 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                    maxSqSize = max(maxSqSize,dp[i][j]);
                }
            }
        }
        return maxSqSize*maxSqSize;
    }
};

int main()
{   vector<vector<char>> mat = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<Solution().maximalSquare(mat);
    return 0;
}
