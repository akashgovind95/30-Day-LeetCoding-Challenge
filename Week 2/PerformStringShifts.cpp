/*

***LEETCODE URL: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3299/****


You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

Example 1:
Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"

Example 2:
Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
 
Constraints:
1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100

*/

/*
Approach:
1. Loop through the shift vector.
2. Take a variable to maintain total shifts (here 'totalShift').
3. For each left shift, decrement totalShift by the the number of left shifts. For each right shift, increment the variable similarly.
4. Also, don't forget to mod totalShift by the size of the string (totalShift % SizeOfString). It helps in avoiding redundant shifts.
5. If totalShift is less than 0, then left shift the entire string by abs(totalShift) times. Else, right shift the string by abs(totalShift) times.
6. Instead of actually looping through the string and shifting the characters, find the final index for each index after shifting and simply place the character at that index in a temporary string (here 'finalS').
7. return finalS.

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    string leftShift(string s, int n){
        
        string finalS = s;
        int size = s.size(); 
        n=n%size;
        for(int i =0;i<size;i++){
            int k;
            if(i >= n)
                k = i-n;
            else
                k = size-(n-i);
            finalS[k] = s[i];
        }
        
        return finalS;
        
        
    }
    string rightShift(string s,int n){
        
        string finalS = s;
        int size = s.size(); 
        n=n%size;
        for(int i =0;i<size;i++){
            int k;
            if(i+n>size-1)
                k = (i+n)-(size) ;
            else
                k=i+n;
            finalS[k] = s[i];
        }
        
        return finalS;
        
        
    }
    string stringShift(string s, vector<vector<int>>& shift) {
        
        int totalShift = 0;
        for(auto i : shift)
            if(i[0]==0)
                totalShift-=i[1];
            else
                totalShift+=i[1];
        
        if(totalShift<0)
            return leftShift(s,abs(totalShift));
        return rightShift(s,abs(totalShift));
        
    }
};


int main()
{
    vector<vector<int>> vec = {{1,1},{1,1},{0,2},{1,3}};
    string s = "abcdefg";
    cout<<Solution().stringShift(s,vec);

    return 0;
}
