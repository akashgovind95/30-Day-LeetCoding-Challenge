/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: [5,7]
Output: 4
*/

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
   int rangeBitwiseAnd(int m, int n) {
        if(!(m && n) || (int)log2(n)>(int)log2(m)) return 0;
        for(int i=m;i<n;i++)    m&=i;
        return m&n;
    }
};

int main()
{
    cout<<Solution().rangeBitwiseAnd(5,7);
    return 0;
}