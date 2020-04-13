/*
Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.

Example 2:
Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.

Note:
The number of nodes in the given list will be between 1 and 100.

*/

/*
Approach:
1. Take two pointers, increment them with speed of 1 and 2 respectively.
2. Keep incrementing them until the fast moving pointer in on the last element or becomes null.
3. Return the slow pointer.
*/

#include <iostream>
#include <vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode * fast = head;
        ListNode * slow = head;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow;
    }
};

ListNode* vectorToLinkedList(vector<int> vec)                         //copying array elements and create linked list
{
    ListNode *temp = new ListNode(vec[0]);
    ListNode *head = temp;
    for(int i=1;i<vec.size();i++)
    {
        ListNode *temp2= new ListNode(vec[i]);
        temp->next= temp2;
        temp=temp2;
    }
    return head;
}

int main()
{
    Solution obj;
    vector<int> vec = {1,2,3,4,5,6};
    ListNode* head = vectorToLinkedList(vec);
    cout<<obj.middleNode(head)->val;
    return 0;
}