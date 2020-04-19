/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

*/

/*
Approach:
1. Let start = 0 and end = sizeofArr - 1.
2. Let mid  = (start+end)/2
3. Check if the target exists at mid. If yes, return mid. Else, continue.
4. Check if element at start <= element at mid, If yes, check if the "target" exists between "start" and "mid" and set "start" and "end" accordingly. Else, check if the "target" exists between "mid" and "end" and set "start" and "end" accordingly.
6. Repeat steps 2 to 4 until start is less than 

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int start = 0;
        int end = nums.size()-1;
        while(start<end){
            int mid = (start+end)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[start]<=nums[mid])
                if(target>=nums[start] && target < nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            else
                if(target>nums[mid] && target<=nums[end])
                    start=mid+1;
                else
                    end = mid-1;
        }
       if(nums[start]==target)
           return start;
        else
            return -1;
    }
};

int main ()
{
    
    vector<int> vec = {4,5,6,7,0,1,2};
    cout<<Solution().search(vec,0)<<endl;
    cout<<Solution().search(vec,3);

  return 0;
}
