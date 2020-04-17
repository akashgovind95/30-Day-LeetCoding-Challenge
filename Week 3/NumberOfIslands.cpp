/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: 
11110
11010
11000
00000

Output: 1
*/

/*
Idea is to find clusters of 1s and mark them with '*' so that if the 1s are encountered again then they are not counted twice. 

Algorithm (DFS):
1. Loop through the grid.
2. Whenever a 1 is encountered, set the element to equal '*' (so that it is never counted again).
3. Call the DFS in all 4 directions

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
     void dfs(int i,int j, int m, int n, vector<vector<char>>& grid){
        
        grid[i][j] = '*';
        if(i+1<m && grid[i+1][j]=='1')
            dfs(i+1,j,m,n,grid);
        if(i-1>=0 && grid[i-1][j]=='1')
            dfs(i-1,j,m,n,grid);
        if(j+1<n && grid[i][j+1]=='1')
            dfs(i,j+1,m,n,grid);
        if(j-1>=0 && grid[i][j-1]=='1')
            dfs(i,j-1,m,n,grid);
            
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        if(rows==0)
            return 0;
        int cols = grid[0].size();
        if(cols==0)
            return 0;
        int count = 0;
        for(int i=0;i<rows;i++){
            for(int j=0; j<cols;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,rows,cols,grid);
                }
            }
        }
        return count;
    }
};



int main()
{
    vector<vector<char>> vec= {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout<<Solution().numIslands(vec);
    
    return 0;
}
