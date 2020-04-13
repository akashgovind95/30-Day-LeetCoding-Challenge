/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

/*
Approach 1: 
1. Use Kadane's algorithm.
2. Keep adding each digit in the array.
3. Keep comparing the sum with the max variable to keep track of the max sum so far. 
4. Whenever the sum < 0, set sum as 0.
5. return max

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     
     int maxSubArray(vector<int>& nums) {
        int Max = -2147483648;
        int curr = 0;
        for(int i = 0;i<nums.size();i++){
            curr+=nums[i];
            Max = max(curr,Max);
            if(curr<0)
                curr=0;
        }
        return Max;
    }
};

int main()
{
    Solution obj;
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<obj.maxSubArray(vec);
    return 0;
}