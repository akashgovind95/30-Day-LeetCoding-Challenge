/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //let's call an index 'goodIndex' if the last index is reachable from there.
        int  goodIndex = nums.size()-1; 
        for(int i=nums.size()-2;i>=0;i--)
            if(nums[i]>=goodIndex - i) //For every index, check if the last goodIndex reachable from there.
                goodIndex = i; //If yes, make the current index as the goodIndex
        
        return (goodIndex>0)?false:true;
    }   
};
int main()
{
    vector<int> nums = {3,2,1,0,4};
    cout<<Solution().canJump(nums);

    return 0;
}
