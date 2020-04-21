/*
A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

Exampl 1:
Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:
Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:
Input: mat = [[0,0],[0,0]]
Output: -1

Example 4:
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
 

Constraints:

1 <= mat.length, mat[i].length <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.
*/

/*
Approach:
1. For each row, run a binary search to find the index of the first occurence of 1.
2. Return the minimum of these indexes

*/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int min_col = INT_MAX;
        for(int i=0;i<dim[0];i++){
            int start = 0;
            int end = dim[1]-1;
            while(start<end){
                int mid = (start+end)/2;
                if(binaryMatrix.get(i, mid)==1)
                    if(mid-1 >=0 && binaryMatrix.get(i, mid-1)==0){
                        min_col = min(min_col,mid);
                        break;
                    }
                    else
                        end = mid-1;
                else
                    start=mid+1;
            }
            
            if(binaryMatrix.get(i, start)==1) min_col = min(min_col,start);
            if(min_col == 0) return min_col;
        }
           
        return (min_col==INT_MAX)?-1:min_col;
        
    }
};