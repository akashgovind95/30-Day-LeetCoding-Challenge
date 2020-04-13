/*
Question: 
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4
*/

/*

Approach:
1. XOR each element in the array and save in a variable
2. This variable will contain the only non repeating number.
3. return this variable. 

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum=0;
        for(int i = 0;i<nums.size();i++)
            sum^=nums[i];
        return sum;
    }
};

int main()
{
    Solution obj;
    vector<int> vec = {4,1,2,1,2};
    cout<<obj.singleNumber(vec);
    return 0;
}