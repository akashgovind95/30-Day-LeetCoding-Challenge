/*
Given an integer array arr, count element x such that x + 1 is also in arr.
If there're duplicates in arr, count them seperately.

Example 1:
Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.

Example 2:
Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.

Example 3:
Input: arr = [1,3,2,3,5,0]
Output: 3
Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.

Example 4:
Input: arr = [1,1,2,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.

Constraints:

1 <= arr.length <= 1000
0 <= arr[i] <= 1000

*/

/*
Approach 

1. Loop the input array. For every element that is found in arr, increase the count in a unordered map. Also, maintain a variable 'count' to keep a track of all elements that satisfy the condition.
2. Loop the array again. For each element x, check if element x+1 also exists in the map. If yes, increment 'count' else continue.
3. Return count

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto i : arr)
            m[i]++;
        int count =0;
        for(auto i : arr)
            if(m.count(i+1) > 0)
                    count++;
        
        return count;
    }
};

int main()
{
    Solution obj;
    vector<int> vec = {1,1,3,3,5,5,7,7};
    cout<<obj.countElements(vec);
    return 0;
}