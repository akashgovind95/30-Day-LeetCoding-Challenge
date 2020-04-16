/*

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

*/

/*
Approach: 

1. Let maxOpenB be the maximum number of open brackets
2. Let minOpenB be the minimum number of open brackets
3. When we encounter:
	- '(' : increment minOpenB and maxOpenB
	- ')' : decrement minOpenB and maxOpenB
	- '*' : increment maxOpenB and decrement minOpenB ('*' can be a open bracket or close bracket) 
4. Keep checking if maxOpenB is less than 0. If yes, return 0 (This means count of close bracket are more than open bracket and '*'  in the current sequence)
5. Also, minOpenB should froced to 0 as the number of open bracket cannot be less than 0
6. return true if minOpenB is 0 or else return false.

*/


#include <iostream>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        
        int maxOpenB = 0;
        int minOpenB = 0;
        for(auto c : s){
            if(c == '('){
                maxOpenB++;
                minOpenB++;
            }
            else if(c == ')'){
                maxOpenB--;
                minOpenB--;
            }
            else{
                maxOpenB++;
                minOpenB--;
            }
            if(maxOpenB<0)
                return false;
            minOpenB = max(0,minOpenB);
            
        }
        
        if(minOpenB == 0)
            return true;
        return false;
    }
};


int main()
{
    cout<<Solution().checkValidString("(*))");
    return 0;
}
