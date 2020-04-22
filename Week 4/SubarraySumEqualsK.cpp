/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

*/

/*
Intuition:
For k to exist as a sum of subarray, then there should be an subarray with sum "x" and and a subarray with sum "k-x" 
Approach:
1. Loop through the array and save the cummulative sum and store it in a map in the form (sum : occurences)
2. In each iteration, find if "sum - k" also exists in the array. If yes, increment a counter varibable by the number of its occurences
3. If "sum-k" doesn't exist in the map, simply increement the occurences of cummulative sum in the map.
4. return the counter varibable
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m{{0,1}};
        int count = 0,sum=0;
        for(int  i = 0;i<nums.size();i++){
            sum+=nums[i];
            if(m.count(sum-k)>0)
                count+=m[sum-k];
            m[sum]++;
        }
        return count;
    }
};

int main()
{
    vector<int> vec  = {1,2,4,5,4,1,4,-3,8};
    cout<<Solution().subarraySum(vec,5);

    return 0;
}
