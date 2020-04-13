/*
We have a collection of stones, each stone has a positive integer weight.
Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)


Example 1:
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 
Note:
1 <= stones.length <= 30
1 <= stones[i] <= 1000

*/

/*
Approach: 

1.Insert all numbers in priority queue.
2. Take top 2 and check if they are same. If yes, insert 0. Else, insert abs(top1 - top2). Continue this process until the size of the priority queue is 1.
3. Return top element of the priority queue.


*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        for(auto i : stones){
            pq.push(i);
        }
        while(pq.size()!=1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x!=y)
                pq.push(abs(x-y));
            else
                pq.push(0);
        }
        
        return pq.top();
    }
};

int main()
{
    vector<int> value= {2,7,4,1,8,1};
    cout<<Solution().lastStoneWeight(value);
    return 0;
}