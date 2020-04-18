/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/

/*

Appraoch:
One thing to keep in mind is that, you can arrive on an index only from the top or the left element. 

1. Loop through the grid
1. If i==0 and j==0, continue
2. If i==0 or j==0, either the top or the left element is missing hence only one way to arrive.
3. Else, take minimum(distance to reach [i-1,j], distance to reach [i,j-1]) because both top and left element exist

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<columns;j++){
                if(i==0&&j==0)
                    continue;
                else if(i==0||j==0){   
                    if(i==0)
                        grid[i][j] += grid[i][j-1];
                    else
                        grid[i][j] += grid[i-1][j];     
                }
                else
                    grid[i][j] += min(grid[i][j-1],grid[i-1][j]); 
            }
        }
        return grid[rows-1][columns-1];
    }
};


int main()
{
    vector<vector<int>> vec = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<Solution().minPathSum(vec);

    return 0;
}
