/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

*/

/*

Approach:
1. The idea is to find the product of all the elements on the left of an element i and multiply it with the product of all the elements on the right of that element.
2. Take an array (same as the size of the original array but initialized with 1) (finalSol here). Take two variables (start and end) to maintain left product and right product for each element i.
3. Loop the array and start populating array to get left product and right product simulataneously.
4. For an element i, left product -> (finalSol[i] = finalSol[i] * start) and right product -> (finalSol[i] = finalSol[i] * end).
5. Keep updating start and end by multiplying them with the current element.
6. return the finalSol array.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size();
        vector<int> finalSol(size,1);
        int end =1;
        int start =1;
        
        for(int i=0; i<size;i++){   
            finalSol[i]*=start;
            start*=nums[i];
            finalSol[size-i-1]*= end;
            end*=nums[size-i-1];
        }
        
        return finalSol;
    }
}; 


int main()
{
    vector<int> nums = {1,2,3,4};
    vector<int> res;
    res=Solution().productExceptSelf(nums);
    for(auto i : res)
        cout<<i<<" ";
    return 0;
}

